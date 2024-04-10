#include<bits/stdc++.h>
#define N 100
using namespace std;
bool f[N+5][N+5][2]; //0,1
int T,n,num[2];
int main()
{
    f[0][0][0]=1;for(int i=0;i<=N;++i) for(int j=0;j<=N;++j)
    {
        if(i) f[i][j][0]|=!f[i-1][j][(j&1)^1],f[i][j][1]|=!f[i-1][j][(j&1)];
        if(j) f[i][j][0]|=!f[i][j-1][(j&1)^1],f[i][j][1]|=!f[i][j-1][(j&1)];
    }
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),num[0]=num[1]=0;
        for(int i=1,a;i<=n;++i)
            scanf("%d",&a),++num[a&1];
        puts(f[num[0]][num[1]][0]?"Alice":"Bob");
    }
    return 0;
}