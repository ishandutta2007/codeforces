#include <bits/stdc++.h>
using namespace std;
int n,m;
bool t;
string s;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>s;
            if (s!="B" && s!="W" && s!="G") t=true;
        }
    }
    if (t==false) cout<<"#Black&White";
    else cout<<"#Color";
}