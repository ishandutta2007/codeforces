#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int q,n,flag;
char s[2][200005];
inline void dfs(int x,int y,int now){
    if (y>1||y<0)return;
    if (x==n+1&&y==1){
        flag=1;
        return;
    }
    if (x>n)return;
    if (now==0){
        if (s[y][x]=='1'||s[y][x]=='2')dfs(x+1,y,0);
        else dfs(x,y-1,1),dfs(x,y+1,1);
    }
    else{
        if (s[y][x]=='3'||s[y][x]=='4'||s[y][x]=='5'||s[y][x]=='6')dfs(x+1,y,0);
    }
    return;
}
int main(){
    cin>>q;
    while(q--){
        cin>>n;
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        flag=0;
        dfs(1,0,0);
        if (flag==1)puts("YES");
        else puts("NO");
    }
    return 0;
}