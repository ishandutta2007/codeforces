//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int dp[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0, m=0, mod=1e9+7;
    string s;
    cin>>n>>s;
    int la[26], pr[n];
    for(int a=0; a<26; a++) la[a]=0;
    while(yk<n)
    {
        char cu=s[yk];
        while(yk<n)
        {
            if(s[yk]==cu) yk++;
            else break;
        }
        pr[m]=la[cu-'a'], la[cu-'a']=m+1;
        m++;
    }
    int dp[n+1][m];
    for(int a=0; a<=n; a++) for(int b=0; b<m; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=1; a<=n; a++)
    {
        int pref[m+1];
        pref[0]=0;
        for(int b=1; b<=m; b++) pref[b]=(pref[b-1]+dp[a-1][b-1])%mod;
        for(int b=0; b<m; b++)
        {
            dp[a][b]+=pref[b+1]-pref[pr[b]];
            if(dp[a][b]<0) dp[a][b]+=mod;
        }
    }
    int an=0;
    for(int a=0; a<m; a++) an=(an+dp[n][a])%mod;
    cout<<an;
}