#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[55][55];
int n,m;
int f[55][55];
int valid(int x,int y){
    if(!x||!y||x>n||y>m) return 0;
    return 1;
}
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
int ddx[4]={1,1,-1,-1},ddy[4]={1,-1,-1,1};
int id(int x,int y){
    return (x-1)*m+y;
}
int fa[2505],sz[2505];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                fa[id(i,j)]=id(i,j),sz[id(i,j)]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                for (int k = 0; k < 4; k++)
                    if (s[i][j] == '*') if (valid(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == '*') {
                        f[i][j]++;
                        int x = find(id(i, j)), y = find(id(i + dx[k], j + dy[k]));
                        if (x != y) fa[y] = x, sz[x] += sz[y];
                    }
            }
        int fl=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='*'){
                    if(sz[find(id(i,j))]!=3) fl=0;
                    if(f[i][j]==1){
                        int cnt=0;
                        for(int k=0;k<4;k++)
                            if(valid(i+ddx[k],j+ddy[k])&&s[i+ddx[k]][j+ddy[k]]=='*')
                                cnt++;
                        if(cnt!=1) fl=0;
                    }
                    else if(f[i][j]==2){
                        int cnt=0;
                        for(int k=0;k<4;k++)
                            if(valid(i+ddx[k],j+ddy[k])&&s[i+ddx[k]][j+ddy[k]]=='*')
                                cnt++;
                        if(cnt) fl=0;
                    }
                    else fl=0;
                }
        puts(fl?"YES":"NO");
    }
    return 0;
}