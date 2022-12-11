#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,x,y,xx,yy;char c[N][N];bool flag[N][N];
void fail(){
    puts("NO");exit(0);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=m;j++){
            if(c[i][j]=='*'){
                x=i,yy=j;flag=1;break;
            }
        }
        if(flag)break;
    }
    if(yy==1||yy==m)fail();
    for(int i=x;i<=n;i++){
        if(c[i][yy+1]=='*'||c[i][yy-1]=='*'){
            xx=i;break;
        }
    }
    if(!xx||!yy)fail();
    for(int i=xx;i>=0;i--){
        if(c[i][yy]!='*'){
            if(i==xx-1)fail();
            break;
        }
        flag[i][yy]=1;
    }
    for(int i=xx;i<=n+1;i++){
        if(c[i][yy]!='*'){
            if(i==xx+1)fail();
            break;
        }
        flag[i][yy]=1;
    }
    for(int i=yy;i;i--){
        if(c[xx][i]!='*'){
            if(i==yy-1)fail();
            break;
        }
        flag[xx][i]=1;
    }
    for(int i=yy;i<=m;i++){
        if(c[xx][i]!='*'){
            if(i==yy+1)fail();
            break;
        }
        flag[xx][i]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(c[i][j]=='*'&&!flag[i][j])fail();
    }
    puts("YES");
    return 0;
}