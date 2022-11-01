#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","tree-vectorize","opt-info-vec-all","fast-math")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
using namespace std;

int n,w,q,x[100005],k[100005],l[100005],r[100005],a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>w>>q;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<q;i++)cin>>k[i];
    memset(l,-1,sizeof(l));
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            l[j]=l[j]<x[i]?x[i]:l[j];
            r[j]=r[j]>x[i]+w?x[i]+w:r[j];
            if(r[j]-l[j]<k[j]){
                a[j]++;
                l[j]=x[i];
                r[j]=x[i]+w;
            }
        }
    }
    for(int i=0;i<q;i++)cout<<a[i]-1<<'\n';

    return 0;
}