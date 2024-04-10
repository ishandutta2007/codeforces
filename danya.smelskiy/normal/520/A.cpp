#include <bits/stdc++.h>
using namespace std;
int a[1000];
int kol;
int n;
string s;
int main(){
    cin>>n;
    cin>>s;
    int x;
    for (int i=0;i<s.size();++i){
        x=s[i];
        if (x>=65 && x<=90) x+=32;
        ++a[x];
        if (a[x]==1) ++kol;
    }
    if (kol==26) cout<<"YES";
    else cout<<"NO";
}