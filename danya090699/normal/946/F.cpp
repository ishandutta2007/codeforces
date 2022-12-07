#include <bits/stdc++.h>
using namespace std;
const int sz=105, mod=1e9+7;
int q[sz], st[sz], pref[sz][sz], suf[sz][sz], sub[sz][sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    string s;
    cin>>s;
    st[0]=2, st[1]=2;
    if(s=="0") q[0]=1;
    if(s=="1") q[1]=1;
    if(n>1)
    {
        if(s[0]=='0') pref[0][1]=1;
        else pref[1][1]=1;
        if(s.back()=='0') suf[0][1]=1;
        else suf[1][1]=1;
    }
    for(int a=1; a<n-1; a++)
    {
        if(s[a]=='0') sub[0][a][a+1]=1;
        else sub[1][a][a+1]=1;
    }
    for(int a=2; a<=x; a++)
    {
        st[a]=(1ll*st[a-1]*st[a-2])%mod;
        q[a]=(1ll*q[a-1]*st[a-2]+1ll*q[a-2]*st[a-1])%mod;
        for(int b=1; b<n; b++) q[a]=(q[a]+1ll*pref[a-1][b]*suf[a-2][n-b])%mod;
        for(int b=1; b<n; b++)
        {
            pref[a][b]=(pref[a-1][b]+1ll*pref[a-2][b]*st[a-1])%mod;
            for(int c=1; c<b; c++) pref[a][b]=(pref[a][b]+1ll*pref[a-1][c]*sub[a-2][c][b])%mod;
        }
        for(int b=1; b<n; b++)
        {
            suf[a][b]=(suf[a-2][b]+1ll*suf[a-1][b]*st[a-2])%mod;
            for(int c=1; c<b; c++) suf[a][b]=(suf[a][b]+1ll*suf[a-2][c]*sub[a-1][n-b][n-c])%mod;
        }
        for(int b=1; b<n-1; b++)
        {
            for(int c=b+1; c<n; c++)
            {
                sub[a][b][c]=(sub[a-1][b][c]+sub[a-2][b][c])%mod;
                for(int d=b+1; d<c; d++) sub[a][b][c]=(sub[a][b][c]+1ll*sub[a-1][b][d]*sub[a-2][d][c])%mod;
            }
        }
    }
    cout<<q[x];
}