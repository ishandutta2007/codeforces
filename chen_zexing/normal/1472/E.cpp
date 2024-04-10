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
struct rec{
    int w,h;
}a[200005];
int ans[200005];
bool cmp1(rec a,rec b){
    return a.w<b.w;
}
int tr[400005],n,id[400005];
void add(int x,int v,int num){
    while(x<=n*2) {
        if(tr[x]>v) tr[x]=v,id[x]=num;
        x += x & -x;
    }
}
int query_value(int x){
    int ans=INT_MAX;
    while(x) ans=min(ans,tr[x]),x-=x&-x;
    return ans;
}
int query_id(int x){
    int now=INT_MAX,ans=-1;
    while(x){
        if(tr[x]<now) now=tr[x],ans=id[x];
        x-=x&-x;
    }
    return ans;
}
int b[400005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        cin >> n;
        int x = 0;
        for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].w, &a[i].h), b[++x] = a[i].w, b[++x] = a[i].h;
        for(int i=1;i<=n*2;i++) tr[i]=INT_MAX;
        sort(b + 1, b + x + 1);
        for (int i = 1; i <= n; i++)
            a[i].w = lower_bound(b + 1, b + n*2 + 1, a[i].w) - b, a[i].h = lower_bound(b + 1, b + n*2 + 1, a[i].h) - b;
        for (int i = 1; i <= n; i++){
            add(a[i].w, a[i].h, i), add(a[i].h, a[i].w, i);
        }
        for (int i = 1; i <= n; i++) {
            //cout<<a[i].w<<" "<<a[i].h<<" "<<query_value(a[i].w)<<endl;
            if(query_value(a[i].w-1)<a[i].h) printf("%d ",query_id(a[i].w-1));
            else printf("-1 ");
        }
        puts("");
    }
    return 0;
}