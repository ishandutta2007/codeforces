#include <bits/stdc++.h>
using namespace std;
long long n,m;
map<string,bool> used;
string s;
long long kol;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s;
        used[s]=true;
    }
    for (int i=1;i<=m;++i){
        cin>>s;
        if (used[s]==true) ++kol;
    }
    n-=kol;
    m-=kol;
    n+=kol/2+kol%2;
    m+=kol/2;
    if (n>m) cout<<"YES";
    else cout<<"NO";
}