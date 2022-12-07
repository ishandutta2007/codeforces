#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        string s;
        cin>>s;
        int n=s.size(), d[n][2];
        for(int a=0; a<n; a++)
        {
            d[a][0]=0, d[a][1]=0;
            if(s[a]=='W') d[a][0]=1;
            if(s[a]=='S') d[a][0]=-1;
            if(s[a]=='A') d[a][1]=1;
            if(s[a]=='D') d[a][1]=-1;
        }
        int pref[n+1][2][2], pos[n+1][2];
        pref[n][0][0]=0, pref[n][0][1]=0, pref[n][1][0]=0, pref[n][1][1]=0;
        pos[n][0]=0, pos[n][1]=0;
        for(int a=n-1; a>=0; a--)
        {
            for(int i=0; i<2; i++)
            {
                pos[a][i]=pos[a+1][i]-d[a][i];
                pref[a][i][0]=min(pref[a+1][i][0], pos[a][i]);
                pref[a][i][1]=max(pref[a+1][i][1], pos[a][i]);
            }
        }
        int p[2]={0, 0}, l[2]={0, 0}, r[2]={0, 0};
        long long an=1ll*(pref[0][0][1]-pref[0][0][0]+1)*(pref[0][1][1]-pref[0][1][0]+1);
        for(int a=0; a<n; a++)
        {
            for(int i=0; i<2; i++)
            {
                int dl=pref[a][i][0]-pos[a][i], dr=pref[a][i][1]-pos[a][i];
                //cout<<dl<<" "<<dr<<"\n";
                int ll=min(l[i], p[i]+1+dl), rr=max(r[i], p[i]+1+dr);
                an=min(an, 1ll*(rr-ll+1)*(pref[0][i^1][1]-pref[0][i^1][0]+1));
                ll=min(l[i], p[i]-1+dl), rr=max(r[i], p[i]-1+dr);
                an=min(an, 1ll*(rr-ll+1)*(pref[0][i^1][1]-pref[0][i^1][0]+1));

                p[i]+=d[a][i];
                l[i]=min(l[i], p[i]);
                r[i]=max(r[i], p[i]);
            }
        }
        cout<<an<<"\n";
    }
}