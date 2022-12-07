#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    map <string, int> fr;
    int qu[n][2];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &qu[a][0]);
        if(qu[a][0]==2)
        {
            char s[50];
            scanf("%s", s);
            string str;
            for(int b=0; s[b]; b++) str.push_back(s[b]);
            if(fr.find(str)==fr.end()) fr[str]=int(fr.size())-1;
            qu[a][1]=fr[str];
        }
    }
    vector <int> sp[m];
    int yk=0;
    while(yk<n)
    {
        yk++;
        int q[m];
        for(int a=0; a<m; a++) q[a]=0;
        while(yk<n)
        {
            if(qu[yk][0]==1) break;
            q[qu[yk][1]]=1;
            yk++;
        }
        for(int a=0; a<m; a++) sp[a].push_back(q[a]);
    }
    int sm[m][m];
    for(int a=0; a<m; a++)
    {
        sm[a][a]=0;
        for(int b=a+1; b<m; b++)
        {
            sm[a][b]=1;
            for(int c=0; c<sp[a].size(); c++) if(sp[a][c] and sp[b][c]) sm[a][b]=0;
            sm[b][a]=sm[a][b];
        }
    }
    int lq=m/2+m%2, rq=m/2;
    int dpl[1<<lq], dpr[1<<rq], gol[lq], gor[rq], golr[lq];

    for(int a=0; a<lq; a++)
    {
        gol[a]=0;
        for(int b=0; b<lq; b++) if(sm[a][b]) gol[a]+=(1<<b);
    }
    for(int a=0; a<(1<<lq); a++) dpl[a]=0;
    dpl[0]=1;
    for(int i=0; i<lq; i++)
    {
        for(int mask=0; mask<(1<<lq); mask++)
        {
            if(__builtin_popcount(mask)==i and dpl[mask])
            {
                for(int v=0; v<lq; v++)
                {
                    if((mask&(1<<v))==0)
                    {
                        if((mask&gol[v])==mask) dpl[mask+(1<<v)]=1;
                    }
                }
            }
        }
    }

    for(int a=0; a<rq; a++)
    {
        gor[a]=0;
        for(int b=0; b<rq; b++) if(sm[lq+a][lq+b]) gor[a]+=(1<<b);
    }
    for(int a=0; a<(1<<rq); a++) dpr[a]=0;
    dpr[0]=0;
    for(int i=0; i<rq; i++)
    {
        for(int mask=0; mask<(1<<rq); mask++)
        {
            if(__builtin_popcount(mask)==i)
            {
                for(int v=0; v<rq; v++)
                {
                    if((mask&(1<<v))==0)
                    {
                        int add=0;
                        if(dpr[mask]==i and (mask&gor[v])==mask) add=1;
                        dpr[mask+(1<<v)]=max(dpr[mask+(1<<v)], dpr[mask]+add);
                    }
                }
            }
        }
    }

    for(int a=0; a<lq; a++)
    {
        golr[a]=0;
        for(int b=0; b<rq; b++) if(sm[a][lq+b]) golr[a]+=(1<<b);
    }
    for(int mask=0; mask<(1<<lq); mask++)
    {
        if(dpl[mask])
        {
            int mask2=(1<<rq)-1;
            for(int i=0; i<lq; i++)
            {
                if(mask&(1<<i)) mask2&=golr[i];
            }
            an=max(an, __builtin_popcount(mask)+dpr[mask2]);
        }
    }
    cout<<an;
}