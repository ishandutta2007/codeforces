#include <bits/stdc++.h>
using namespace std;
long long n,x,maxim=-1e10,y;
long long ans=-1e10;
vector<long long> v[500005];
long long a[500005];
int   main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=2;
        maxim=max(maxim,a[i]);
    }
    for (long long i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    x=0;
    y=0;
    for (long long i=1;i<=n;++i){
        if (a[i]==maxim) ++x;
            else if (a[i]==maxim-1) ++y;
    }
    ans=maxim;
    for (long long i=1;i<=n;++i){
            bool t=false;
        for (long long j=0;j<v[i].size();++j){
            long long to=v[i][j];
            if (a[to]==maxim) { --x; t=true; }
            else if (a[to]==maxim-1) --y;
        }
        if (a[i]==maxim) --x;
        else if (a[i]==maxim-1) --y;
        if (x==0) ans=min(ans,maxim-1);
        if (x==0 && y==0 && t==false) ans=min(ans,maxim-2);
        for (long long j=0;j<v[i].size();++j){
            long long to=v[i][j];
            if (a[to]==maxim)  { ++x; }
            else if (a[to]==maxim-1) ++y;
        }
        if (a[i]==maxim) ++x;
        else if (a[i]==maxim-1) ++y;
    }
    cout<<ans;
}