#include <bits/stdc++.h>
using namespace std;
const int sz=1e5;
int qq=0;
vector <int> sp[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    double mat[14][n][n];
    int ar[n][2];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
        for(int b=0; b<n; b++) mat[0][a][b]=0;
    }
    for(int a=0; a<n; a++)
    {
        map <pair <int, int>, vector <int> > ma;
        for(int b=0; b<n; b++)
        {
            if(a!=b)
            {
                int vx=ar[a][0]-ar[b][0], vy=ar[a][1]-ar[b][1];
                if(vx<0)
                {
                    vx=-vx, vy=-vy;
                }
                int d=__gcd(abs(vx), abs(vy));
                vx/=d, vy/=d;
                if(vx==0) vy=1;
                if(vy==0) vx=1;
                ma[make_pair(vx, vy)].push_back(b);
            }
        }
        double pr=1.0/int(ma.size());
        for(auto it=ma.begin(); it!=ma.end(); it++)
        {
            vector <int> &ve=(*it).second;
            double pr2=pr/(int(ve.size())+1);
            int mi=1e9;
            for(int b=0; b<ve.size(); b++)
            {
                mat[0][ve[b]][a]+=pr2;
                mi=min(mi, ve[b]);
            }
            mat[0][a][a]+=pr2;
            if(mi>a)
            {
                for(int b=0; b<ve.size(); b++) sp[qq].push_back(ve[b]);
                sp[qq].push_back(a);
                qq++;
            }
        }
    }
    for(int i=1; i<14; i++)
    {
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) mat[i][a][b]=0;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++)
            {
                for(int c=0; c<n; c++) mat[i][a][b]+=mat[i-1][a][c]*mat[i-1][c][b];
            }
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int t, m, i=0;
        cin>>t>>m;
        t--, m--;
        double dp[n], dp2[n];
        for(int b=0; b<n; b++)
        {
            dp[b]=0, dp2[b]=0;
        }
        dp[t]=1;
        while(m)
        {
            if(m&1)
            {
                for(int b=0; b<n; b++)
                {
                    for(int c=0; c<n; c++) dp2[c]+=dp[b]*mat[i][b][c];
                }
                for(int b=0; b<n; b++)
                {
                    dp[b]=dp2[b], dp2[b]=0;
                }
            }
            i++, m>>=1;
        }
        double be=0;
        for(int b=0; b<qq; b++)
        {
            double pr=1.0/int(sp[b].size()), su=0;
            for(int c=0; c<sp[b].size(); c++) su+=pr*dp[sp[b][c]];
            be=max(be, su);
        }
        cout<<fixed<<setprecision(10)<<be<<"\n";
    }
}