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
struct seg{
    int l,r;
}a[200005];
bool cmp(seg a,seg b){
    return a.r<b.r;
}
int b[400005];
int tree[400005],n,cnt[200005];
void add(int x){
    while(x<=n*2){
        tree[x]++;
        x+=x&-x;
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=x&-x;
    }
    return ans;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        scanf("%d",&n);
        int x=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].l,&a[i].r),b[++x]=a[i].l,b[++x]=a[i].r;
        }
        for(int i=1;i<=n*2;i++) tree[i]=0;
        sort(b+1,b+x+1);
        for(int i=1;i<=n;i++){
            a[i].l=lower_bound(b+1,b+x+1,a[i].l)-b;
            a[i].r=lower_bound(b+1,b+x+1,a[i].r)-b;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=n;i>=1;i--){
            cnt[i]=query(a[i].r);
            add(a[i].l);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<r){
                int mid=(l+r)>>1;
                if(a[mid].r>=a[i].l) r=mid;
                else l=mid+1;
            }
            ans=max(ans,i-l+1+cnt[i]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}