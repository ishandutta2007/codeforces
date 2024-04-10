#include <bits/stdc++.h>
using namespace std;
const int sz=1e6;
int w, n, m, q[sz], q2[sz], st3[12][3], f[12];
int go[6][2]={{2, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 2}, {1, 0}};
void dfs(int i, int mask, int mask2)
{
    if(i==w) q2[mask2]+=q[mask];
    else
    {
        for(int a=0; a<2; a++)
        {
            for(int b=0; b<2; b++)
            {
                if(b) dfs(i+1, mask+(a<<i), mask2+st3[i][2]);
                else dfs(i+1, mask+(a<<i), mask2+st3[i][a]);
            }
        }
    }
}
int an;
void dfs2(int i, int mask, int mask2)
{
    if(i==w) an+=q[mask]*q2[mask2];
    else
    {
        for(int a=0; a<2; a++)
        {
            if(go[f[i]][a]!=-1)
            {
                dfs2(i+1, mask+(a<<i), mask2+st3[i][go[f[i]][a]]);
            }
        }
    }
}
int main()
{
    st3[0][0]=0, st3[0][1]=1, st3[0][2]=2;
    for(int a=1; a<12; a++) for(int b=0; b<3; b++) st3[a][b]=st3[a-1][b]*3;
    //freopen("input.txt", "r", stdin);
    cin>>w>>n>>m;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    dfs(0, 0, 0);
    for(int a=0; a<m; a++)
    {
        char buf[20];
        scanf("%s", buf);
        reverse(buf, buf+w);
        for(int i=0; i<w; i++)
        {
            if(buf[i]=='A') f[i]=0;
            if(buf[i]=='O') f[i]=1;
            if(buf[i]=='X') f[i]=2;
            if(buf[i]=='a') f[i]=3;
            if(buf[i]=='o') f[i]=4;
            if(buf[i]=='x') f[i]=5;
        }
        an=0;
        dfs2(0, 0, 0);
        printf("%d\n", an);
    }
}