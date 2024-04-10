#include <bits/stdc++.h>
using namespace std;
string s;
bool dp[10005][4];
map<string,bool> used;
vector<string> v;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    reverse(s.begin(),s.end());
    dp[2][2]=true;
    dp[3][3]=true;
    int n=s.size();
    for (int i=2;i<=n-5;++i) {
        if (i>=5 && dp[i-2][3]) dp[i][2]=true;
        else if (i>=4 && (s[i-1]!=s[i-3] || s[i-2]!=s[i-4]) && dp[i-2][2]) dp[i][2]=true;
        if (i>=5 && dp[i-3][2]) dp[i][3]=true;
        else if (i>=6 && (s[i-1]!=s[i-4] || s[i-2]!=s[i-5] || s[i-3]!=s[i-6]) && dp[i-3][3]) dp[i][3]=true;
        if (dp[i][2]) {
            string sk;
            sk=s[i-2];
            sk+=s[i-1];
            if (used[sk]==false) {
                v.push_back(sk);
                used[sk]=true;
            }
        }
        if (dp[i][3]) {
            string sk;
            sk=s[i-3];
            sk+=s[i-2];
            sk+=s[i-1];
            if (used[sk]==false) {
                used[sk]=true;
                v.push_back(sk);
            }
        }
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i) {
        reverse(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<'\n';
}