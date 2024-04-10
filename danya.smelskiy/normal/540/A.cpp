#include <bits/stdc++.h>
using namespace std;
int n;
string s,s1;
long long ans;
int x,y;
int main(){
    cin>>n;
    cin>>s>>s1;
    for (int i=1;i<=n;++i){
        y=s[i-1]-'0';
        x=s1[i-1]-'0';
        ans+=min(abs(y-x),min(10-y+x,10-x+y));
    }
    cout<<ans;
}