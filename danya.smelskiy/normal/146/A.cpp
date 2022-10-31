#include <bits/stdc++.h>
using namespace std;
long long n,first,second;
string s;
int main(){
    cin>>n;
    cin>>s;
    for (int i=1;i<=s.size();++i){
        if (s[i-1]!='4' && s[i-1]!='7'){
            cout<<"NO";
            return 0;
        }
        if (i<=n/2) first+=s[i-1]-'0';
        else second+=s[i-1]-'0';
    }
    if (first!=second) cout<<"NO";
    else cout<<"YES";
}