#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
struct pos{
    int tx,ty;
    int con;
    char mp;
}a[1005][1005];
int n;
void dfs(int x,int y,char c) {
    if(a[x][y].mp!='?') return;
    a[x][y].mp = c;
    if (x + 1 <= n && a[x + 1][y].tx == a[x][y].tx && a[x + 1][y].ty == a[x][y].ty) dfs(x + 1, y, 'U');
    if (x - 1 && a[x - 1][y].tx == a[x][y].tx && a[x - 1][y].ty == a[x][y].ty) dfs(x - 1, y, 'D');
    if (y + 1 <= n && a[x][y + 1].tx == a[x][y].tx && a[x][y + 1].ty == a[x][y].ty) dfs(x, y + 1, 'L');
    if (y - 1 && a[x][y - 1].tx == a[x][y].tx && a[x][y - 1].ty == a[x][y].ty) dfs(x, y - 1, 'R');
}
void link(int x,int y){
    if(x+1<=n&&!a[x+1][y].con) a[x][y].mp='D';
    else if(x-1&&!a[x-1][y].con) a[x][y].mp='U';
    else if(y+1<=n&&!a[x][y+1].con) a[x][y].mp='R';
    else if(y-1&&!a[x][y-1].con) a[x][y].mp='L';
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            scanf("%d%d", &a[i][j].tx, &a[i][j].ty), a[i][j].mp = '?';
            a[i][j].con=a[i][j].tx==-1?0:1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==a[i][j].tx&&j==a[i][j].ty)
                dfs(i,j,'X');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!a[i][j].con){
                link(i,j);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j].mp=='?')
            {
                //cout<<i<<" "<<j<<endl;
                puts("INVALID");
                return 0;
            }
    puts("VALID");
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++)
            printf("%c",a[i][j].mp);
    return 0;
}