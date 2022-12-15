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
struct node{
    int p,t;
    friend bool operator <(node a,node b){
        return a.p>b.p||a.p==b.p&&a.t>b.t;
    }
}a[200005],b[200005];
int h[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&h[i]),mx=max(mx,h[i]);
        cin>>m;
        for(int i=1;i<=m;i++) scanf("%d%d",&a[i].p,&a[i].t);
        sort(a+1,a+m+1);
        int x=0;
        for(int i=1;i<=m;i++) if(i==1||(a[i].p!=a[i-1].p&&a[i].t>b[x].t)) b[++x]=a[i];
        if(mx>a[1].p){
            puts("-1");
            continue;
        }
        int temp=0,ans=0;
        while(temp<n){
            int now=1,r=temp+1,mmx=0,o=temp;
            while(r<=n&&now<=x){
                while(max(h[r],mmx)<=b[now].p&&r-o<=b[now].t) r++,mmx=max(h[r-1],mmx);
                if(r<=temp+1) break;
                temp=r-1,now++;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp