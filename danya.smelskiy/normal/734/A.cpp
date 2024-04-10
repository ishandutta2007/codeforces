#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long a,b;
int main(){
    cin>>n>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='A') ++a;
    else ++b;
    if (a>b) cout<<"Anton";
    else if (b>a) cout<<"Danik";
    else cout<<"Friendship";
}