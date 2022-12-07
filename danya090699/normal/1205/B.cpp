#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
vector <int> sp[60];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        long long x;
        scanf("%lld", &x);
        vector <int> cu;
        for(int i=0; i<60; i++)
        {
            if(x&(1ll<<i)) sp[i].push_back(a);
        }
    }
    map <int, int> ma;
    for(int a=0; a<60; a++)
    {
        if(sp[a].size()>2)
        {
            cout<<3;
            return 0;
        }
        if(sp[a].size()==2)
        {
            ma[sp[a][0]]=0, ma[sp[a][1]]=0;
        }
    }
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=m++;
    int sm[m][m];
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) sm[a][b]=inf;
    for(int a=0; a<60; a++)
    {
        if(sp[a].size()==2)
        {
            sm[ma[sp[a][0]]][ma[sp[a][1]]]=1;
            sm[ma[sp[a][1]]][ma[sp[a][0]]]=1;
        }
    }
    int an=inf;
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(sm[i][j]==1)
            {
                sm[i][j]=inf, sm[j][i]=inf;
                int di[m], us[m];
                for(int a=0; a<m; a++) di[a]=inf, us[a]=0;
                di[i]=0;
                for(int a=0; a<m; a++)
                {
                    int be=-1;
                    for(int b=0; b<m; b++)
                    {
                        if(us[b]==0 and (be==-1 or di[b]<di[be])) be=b;
                    }
                    us[be]=1;
                    for(int b=0; b<m; b++) di[b]=min(di[b], di[be]+sm[be][b]);
                }
                an=min(an, di[j]+1);
                sm[i][j]=1, sm[j][i]=1;
            }
        }
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}