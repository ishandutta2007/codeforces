#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,s1;
map<string,string> a;
string b[10000];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>s>>s1;
        a[s]=s1;
    }
    for (int i=1;i<=n;++i){
        cin>>s;
        if (a[s].size()<s.size()) b[i]=a[s];
        else b[i]=s;
    }
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
}