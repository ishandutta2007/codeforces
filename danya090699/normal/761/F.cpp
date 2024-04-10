//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int n, m, k, q[26][sz][sz];
long long di[sz][sz], ds[26][sz][sz];
string ar[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>k;
    int za[k][5];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int c=0; c<26; c++) for(int a=0; a<n; a++) for(int b=0; b<n; b++) q[c][a][b]=0;
    for(int a=0; a<k; a++)
    {
        int y1, x1, y2, x2, sn;
        char sy;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        cin>>sy;
        y1--, x1--, y2--, x2--, sn=sy-'a';
        za[a][0]=y1, za[a][1]=x1, za[a][2]=y2, za[a][3]=x2, za[a][4]=sn;
        for(int b=y1; b<=y2; b++)
        {
            q[sn][b][x1]++, q[sn][b][x2+1]--;
        }
    }
    for(int a=0; a<26; a++)
    {
        for(int b=0; b<n; b++)
        {
            int cu=0;
            for(int c=0; c<m; c++)
            {
                cu+=q[a][b][c], q[a][b][c]=cu;
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int sn=ar[a][b]-'a', qq=k;
            di[a][b]=0;
            for(int c=0; c<26; c++)
            {
                qq-=q[c][a][b];
                int mo=sn-c;
                if(mo<0) mo=-mo;
                di[a][b]+=q[c][a][b]*mo;
            }
            q[sn][a][b]+=qq;
            if(a>0) di[a][b]+=di[a-1][b];
            if(b>0) di[a][b]+=di[a][b-1];
            if(a>0 and b>0) di[a][b]-=di[a-1][b-1];
            ds[0][a][b]=0;
            int lq=0;
            for(int c=0; c<26; c++) ds[0][a][b]+=c*q[c][a][b];
            for(int c=1; c<26; c++)
            {
                lq+=q[c-1][a][b];
                ds[c][a][b]=ds[c-1][a][b]+lq-(k-lq);
            }
            for(int c=0; c<26; c++)
            {
                if(a>0) ds[c][a][b]+=ds[c][a-1][b];
                if(b>0) ds[c][a][b]+=ds[c][a][b-1];
                if(a>0 and b>0) ds[c][a][b]-=ds[c][a-1][b-1];
            }
        }
    }
    long long best=1e18;
    for(int a=0; a<k; a++)
    {
        int y1=za[a][0], x1=za[a][1], y2=za[a][2], x2=za[a][3], sn=za[a][4];
        long long an=di[n-1][m-1], out=di[y2][x2];
        if(y1>0) out-=di[y1-1][x2];
        if(x1>0) out-=di[y2][x1-1];
        if(y1>0 and x1>0) out+=di[y1-1][x1-1];
        an-=out;
        long long add=ds[sn][y2][x2];
        if(y1>0) add-=ds[sn][y1-1][x2];
        if(x1>0) add-=ds[sn][y2][x1-1];
        if(y1>0 and x1>0) add+=ds[sn][y1-1][x1-1];
        best=min(best, an+add);
    }
    cout<<best;
}