#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y;
bool usedx[1000001],usedy[1000001];
long long kolx,koly;
vector<long long> v;
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (usedx[x]==false) ++kolx;
        if (usedy[y]==false) ++koly;
        unsigned long long kol=n*n-kolx*n-koly*n+kolx*koly;
        v.push_back(kol);
        usedx[x]=true;
        usedy[y]=true;
    }
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}