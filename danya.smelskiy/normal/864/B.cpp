#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int dp[205];
inline void solve(string ss){
    for (int i=0;i<26;++i)
        dp[i]=0;
    for (int i=0;i<ss.size();++i)
        ++dp[ss[i]-'a'];
        int res=0;
    for (int i=0;i<26;++i)
    if (dp[i]) ++res;
    ans=max(ans,res);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    string last="";
    for (int i=0;i<s.size();++i) {
        if (s[i]>='a' && s[i]<='z') {
            last+=s[i];
            solve(last);
        } else last="";
    }
    cout<<ans;
}