#include <bits/stdc++.h>
using namespace std;
long long n,x,y;
string s;
int main(){
    cin>>n>>x>>y;
    cin>>s;
    --x;
    --y;
    if (s[x]==s[y]) cout<<"0";
    else cout<<"1";
}