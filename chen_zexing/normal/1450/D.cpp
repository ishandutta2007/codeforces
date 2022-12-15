#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[300005],cnt[300005],ans[300005];
int tree[1200005];
void build(int node,int l,int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node * 2],tree[node * 2 + 1]);
}
int query(int node,int l,int r,int L,int R) {
    if (l >= L && r <= R) {
        return tree[node];
    }
    int mid = (l + r) >> 1;
    int ans = INT_MAX;
    if (mid >= L) ans = min(ans, query(node * 2, l, mid, L, R));
    if (mid < R) ans = min(ans, query(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        build(1,1,n);
        ans[n]=query(1,1,n,1,n)==1;
        int l=1,r=n,f=1;
        for(int i=n-1;i>=2;i--){
            int temp=n-i;
            if(!f){
                ans[i]=0;
                continue;
            }
            if(a[l]==a[r]&&a[l]==temp||a[l]!=temp&&a[r]!=temp){
                f=0;
                ans[i]=0;
                continue;
            }
            if(a[l]==temp) l++;
            else if(a[r]==temp) r--;
            if(query(1,1,n,l,r)==temp+1) ans[i]=1;
            else ans[i]=0,f=0;
        }
        ans[1]=1;
        for(int i=1;i<=n;i++) if(cnt[i]!=1) ans[1]=0;
        for(int i=1;i<=n;i++) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}