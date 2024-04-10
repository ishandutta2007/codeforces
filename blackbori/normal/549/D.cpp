#include <bits/stdc++.h>

using namespace std;

string s;
int n,m;
int D[103][103], E[103][103];

int Fill(int x,int y,int k)
{
    int i,j;
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            E[i][j]+=k;
        }
    }

    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d",&n,&m);

    char a;
    int i,j;
    for(i=1; i<=n; i++){
        cin >> s;
        for(j=1; j<=m; j++){
            if(s[j-1]=='B') D[i][j] = -1;
            else D[i][j] = 1;
        }
    }

    int x, y;
    x=n; y=m;
    int sum=0;
    while(true){
        while(true){
            if(D[x][y] != E[x][y]) break;
            y--; if(y==0) y=m, x--;
            if(x==0) break;
        }
        if(x==0) break;
        Fill(x,y,D[x][y]-E[x][y]);
        sum++;
    }

    printf("%d\n",sum);

    return 0;
}