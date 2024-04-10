#include <bits/stdc++.h>
using namespace std;

string s;
int sz;
int dp[1000005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int l=0;
    while (l<s.size() && s[l]=='F') ++l;
    if (l==s.size()) {
        cout<<"0";
        return 0;
    }
    string ss="";
    for (int i=l;i<s.size();++i)
        ss+=s[i];
    s=ss;
    s="#"+s;
    for (int i=1;i<s.size();++i) if (s[i]=='F'){
        ++sz;
        dp[sz]=max(i-sz,dp[sz-1]+1);
    }
    cout<<dp[sz];
}