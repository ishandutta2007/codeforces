#include <bits/stdc++.h>
using namespace std;
int k[4][2]={{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, qq;
	cin>>n>>m>>qq;
	int q[4][n+1][m+1], be[n+1][m+1];
	for(int i=0; i<4; i++)
    {
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<=m; b++)
            {
                q[i][a][b]=0;
                be[a][b]=1e9;
            }
        }
    }
	for(int a=0; a<n; a++)
    {
        char s[m+1];
        scanf("%s", s);
        for(int b=0; b<m; b++)
        {
            int c;
            if(s[b]=='R') c=0;
            if(s[b]=='G') c=1;
            if(s[b]=='B') c=2;
            if(s[b]=='Y') c=3;
            q[c][a+1][b+1]=1;
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int a=1; a<=n; a++)
        {
            for(int b=1; b<=m; b++) q[i][a][b]+=q[i][a-1][b]+q[i][a][b-1]-q[i][a-1][b-1];
        }
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<=m; b++)
            {
                int l=0, r=min(n, m);
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    int xl=a, yl=b, xr=a+mid*k[i][0], yr=b+mid*k[i][1];
                    if(xl>xr) swap(xl, xr);
                    if(yl>yr) swap(yl, yr);
                    if(xl>=0 and xr<=n and yl>=0 and yr<=m)
                    {
                        if(q[i][xr][yr]-q[i][xl][yr]-q[i][xr][yl]+q[i][xl][yl]==mid*mid) l=mid;
                        else r=mid;
                    }
                    else r=mid;
                }
                be[a][b]=min(be[a][b], l);
            }
        }
    }
    int sp[qq][4], an[qq];
    for(int a=0; a<qq; a++)
    {
        for(int i=0; i<4; i++) scanf("%d", &sp[a][i]);
        sp[a][0]--, sp[a][1]--;
        an[a]=0;
    }
    for(int a=min(n, m)/2; a; a--)
    {
        int q[n+1][m+1];
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<=m; c++)
            {
                q[b][c]=(be[b][c]>=a);
                if(b and c) q[b][c]+=q[b-1][c]+q[b][c-1]-q[b-1][c-1];
            }
        }
        for(int b=0; b<qq; b++)
        {
            if(!an[b])
            {
                int lx=sp[b][0]+a, ly=sp[b][1]+a, rx=sp[b][2]-a, ry=sp[b][3]-a;
                if(lx<=rx and ly<=ry)
                {
                    int su=q[rx][ry];
                    if(lx) su-=q[lx-1][ry];
                    if(ly) su-=q[rx][ly-1];
                    if(lx and ly) su+=q[lx-1][ly-1];
                    if(su) an[b]=(a+a)*(a+a);
                }
            }
        }
    }
    for(int a=0; a<qq; a++) printf("%d\n", an[a]);
}