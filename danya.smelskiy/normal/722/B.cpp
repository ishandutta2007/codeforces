#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int kol;
string s;
bool t,tt;
int main(){
    cin>>n;
    for (int i=2;i<=n+1;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n+1;++i){
        getline(cin,s);
        t=false;
        kol=0;
        for (int i=0;i<s.size();++i)
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
        ++kol;
        if (kol!=a[i]) tt=true;
    }
    if (tt==false) cout<<"YES"; else cout<<"NO";
}