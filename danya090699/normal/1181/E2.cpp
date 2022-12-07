#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ar[sz][2][2], cnu[sz], qq=1;
bool comp00(int a, int b)
{
    if(ar[a][0][0]!=ar[b][0][0]) return ar[a][0][0]>ar[b][0][0];
    else return a<b;
}
bool comp01(int a, int b)
{
    if(ar[a][0][1]!=ar[b][0][1]) return ar[a][0][1]<ar[b][0][1];
    else return a<b;
}
bool comp10(int a, int b)
{
    if(ar[a][1][0]!=ar[b][1][0]) return ar[a][1][0]>ar[b][1][0];
    else return a<b;
}
bool comp11(int a, int b)
{
    if(ar[a][1][1]!=ar[b][1][1]) return ar[a][1][1]<ar[b][1][1];
    else return a<b;
}
bool dfs(int nu, int q, vector <int> (*sp)[2])
{
    if(q==1) return true;

    vector <int> st[2][2], sp2[2][2];

    int pr[2][2], nu2, cut=0;

    for(int a=0; a<q; a++)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                while(cnu[sp[i][j].back()]!=nu) sp[i][j].pop_back();
                int x=sp[i][j].back();
                if(a==0)
                {
                    if(j==0) pr[i][j]=ar[x][i][1];
                    else pr[i][j]=ar[x][i][0];
                }
                else
                {
                    if(j==0)
                    {
                        if(pr[i][j]<=ar[x][i][0]) cut=1;
                        pr[i][j]=max(pr[i][j], ar[x][i][1]);
                    }
                    else
                    {
                        if(pr[i][j]>=ar[x][i][1]) cut=1;
                        pr[i][j]=min(pr[i][j], ar[x][i][0]);
                    }
                }
                if(cut)
                {
                    nu2=qq++;
                    for(int b=0; b<st[i][j].size(); b++)
                    {
                        for(int i2=0; i2<2; i2++)
                        {
                            for(int j2=0; j2<2; j2++)
                            {
                                int x2=st[i][j][b];
                                cnu[x2]=nu2;
                                sp2[i2][j2].push_back(x2);
                            }
                        }
                    }
                    break;
                }
                else
                {
                    sp[i][j].pop_back(), st[i][j].push_back(x);
                }
            }
            if(cut) break;
        }
        if(cut) break;
    }

    if(cut==0) return false;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            while(st[i][j].size())
            {
                sp[i][j].push_back(st[i][j].back());
                st[i][j].pop_back();
            }
        }
    }

    sort(sp2[0][0].begin(), sp2[0][0].end(), comp00);
    sort(sp2[0][1].begin(), sp2[0][1].end(), comp01);
    sort(sp2[1][0].begin(), sp2[1][0].end(), comp10);
    sort(sp2[1][1].begin(), sp2[1][1].end(), comp11);

    return (dfs(nu, q-sp2[0][0].size(), sp) and dfs(nu2, sp2[0][0].size(), sp2));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> sp[2][2];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<2; c++)
            {
                scanf("%d", &ar[a][c][b]);
                sp[b][c].push_back(a);
            }
        }
    }
    sort(sp[0][0].begin(), sp[0][0].end(), comp00);
    sort(sp[0][1].begin(), sp[0][1].end(), comp01);
    sort(sp[1][0].begin(), sp[1][0].end(), comp10);
    sort(sp[1][1].begin(), sp[1][1].end(), comp11);

    if(dfs(0, n, sp)) cout<<"YES";
    else cout<<"NO";
}