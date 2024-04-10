#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9, sz2=255;
int pref[sz][26], dp[sz2][sz2][sz2];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, l[3]={0, 0, 0};
    cin>>n>>q;
    char s[n+1];
    scanf("%s", s);
    for(int a=0; a<26; a++) pref[n][a]=inf;
    for(int a=n-1; a>=0; a--)
    {
        for(int b=0; b<26; b++)
        {
            pref[a][b]=pref[a+1][b];
            if(s[a]-'a'==b) pref[a][b]=a+1;
        }
    }
    vector <int> re[3];
    for(int a=0; a<q; a++)
    {
        char ty;
        int i;
        cin>>ty>>i;
        i--;
        if(ty=='+')
        {
            char sy;
            cin>>sy;
            re[i].push_back(sy-'a');

            int gr[3][2];
            for(int b=0; b<3; b++) gr[b][0]=0, gr[b][1]=re[b].size();
            gr[i][0]=gr[i][1];
            for(int q0=gr[0][0]; q0<=gr[0][1]; q0++)
            {
                for(int q1=gr[1][0]; q1<=gr[1][1]; q1++)
                {
                    for(int q2=gr[2][0]; q2<=gr[2][1]; q2++) dp[q0][q1][q2]=inf;
                }
            }
            gr[i][0]--;
            for(int q0=gr[0][0]; q0<=gr[0][1]; q0++)
            {
                for(int q1=gr[1][0]; q1<=gr[1][1]; q1++)
                {
                    for(int q2=gr[2][0]; q2<=gr[2][1]; q2++)
                    {
                        int p=dp[q0][q1][q2];
                        if(p!=inf)
                        {
                            if(q0<re[0].size()) dp[q0+1][q1][q2]=min(dp[q0+1][q1][q2], pref[p][re[0][q0]]);
                            if(q1<re[1].size()) dp[q0][q1+1][q2]=min(dp[q0][q1+1][q2], pref[p][re[1][q1]]);
                            if(q2<re[2].size()) dp[q0][q1][q2+1]=min(dp[q0][q1][q2+1], pref[p][re[2][q2]]);
                        }
                    }
                }
            }
        }
        else re[i].pop_back();

        if(dp[re[0].size()][re[1].size()][re[2].size()]!=inf) cout<<"YES\n";
        else cout<<"NO\n";
    }
}