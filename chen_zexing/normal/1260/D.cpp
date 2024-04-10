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
int a[200005],ll[200005],rr[200005],d[200005],id[200005];
bool cmp(int a,int b){
    return a>b;
}
bool cmp2(int a,int b){
    return ll[a]<ll[b]||ll[a]==ll[b]&&rr[a]<rr[b];
}
vector <int> v;
int main() {
    int m,n,k,t;
    cin>>m>>n>>k>>t;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++) scanf("%d%d%d",&ll[i],&rr[i],&d[i]),id[i]=i;
    sort(a+1,a+m+1,cmp);
    sort(id+1,id+k+1,cmp2);
    a[0]=1e8;
    int l=0,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        mid++;
        int lim=a[mid];
        int mx=0,mn=INT_MAX;
        v.clear();
        int f=0;
        for(int i=1;i<=k;i++)
            if(d[id[i]]>lim)
                v.push_back(id[i]),f=1;
        if(!f){
            l=mid;
            continue;
        }
        long long cnt=ll[v[0]]-1,now=ll[v[0]]-1;
        mx=rr[v[0]];
        for(int i=1;i<v.size();i++){
            //cout<<cnt<<"#"<<mid<<endl;
            if(ll[v[i]]<=mx) mx=max(rr[v[i]],mx);
            else{
                cnt+=(mx-now)*2;
                cnt+=ll[v[i]]-now-1;
                mx=rr[v[i]];
                now=ll[v[i]]-1;
            }
        }
        cnt+=(mx-now)*2;
        cnt+=n+1-now;
        if(cnt<=t) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}