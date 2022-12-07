//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int c[18][sz], p[sz], pn[sz], cnt[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    int n, m, x, n2;
    cin>>n>>s>>m>>t>>x;
    s+=t;
    n2=s.size();
    for(int a=0; a<26; a++) cnt[a]=0;
    for(int a=0; a<n2; a++) cnt[s[a]-'a']++;
    for(int a=1; a<26; a++) cnt[a]+=cnt[a-1];
    for(int a=n2-1; a>=0; a--)
    {
        cnt[s[a]-'a']--;
        p[cnt[s[a]-'a']]=a;
    }
    int cq=1;
    c[0][p[0]]=0;
    for(int a=1; a<n2; a++)
    {
        if(s[p[a]]!=s[p[a-1]]) cq++;
        c[0][p[a]]=cq-1;
    }
    for(int i=0; (1<<(i+1))<=n2; i++)
    {
        for(int a=0; a<n2; a++)
        {
            pn[a]=p[a]-(1<<i);
            if(pn[a]<0) pn[a]+=n2;
        }
        for(int a=0; a<n2; a++) cnt[a]=0;
        for(int a=0; a<n2; a++) cnt[c[i][a]]++;
        for(int a=0; a<n2; a++) cnt[a]+=cnt[a-1];
        for(int a=n2-1; a>=0; a--)
        {
            cnt[c[i][pn[a]]]--;
            p[cnt[c[i][pn[a]]]]=pn[a];
        }
        cq=1;
        c[i+1][p[0]]=0;
        for(int a=1; a<n2; a++)
        {
            int p12=(p[a-1]+(1<<i))%n2, p22=(p[a]+(1<<i))%n2;
            if(c[i][p[a-1]]!=c[i][p[a]] or c[i][p12]!=c[i][p22]) cq++;
            c[i+1][p[a]]=cq-1;
        }
    }
    int dp[x+1][n+1];
    for(int a=0; a<=x; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=x; b++)
        {
            dp[b][a+1]=max(dp[b][a+1], dp[b][a]);
            if(b<x)
            {
                int p1=a, p2=dp[b][a];
                for(int i=17; i>=0; i--)
                {
                    if(p1+(1<<i)<=n and p2+(1<<i)<=m)
                    {
                        if(c[i][p1]==c[i][p2+n])
                        {
                            p1+=(1<<i), p2+=(1<<i);
                        }
                    }
                }
                if(p1>a) dp[b+1][p1]=max(dp[b+1][p1], p2);
            }
        }
    }
    bool pos=0;
    for(int a=0; a<=x; a++) if(dp[a][n]==m) pos=1;
    if(pos) cout<<"YES";
    else cout<<"NO";
}