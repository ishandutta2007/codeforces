#include <bits/stdc++.h>
using namespace std;
int n;
int ans=1;
string s,last;
int main(){
    cin>>n;
    last="22";
    for (int i=1;i<=n;++i){
        cin>>s;
        if (s[0]==last[1]) ++ans;
        last=s;
    }
    cout<<ans;
}