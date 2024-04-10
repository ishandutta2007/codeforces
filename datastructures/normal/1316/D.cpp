#include <iostream>
#include <cstdio>
using namespace std;
int n,x[1005][1005],y[1005][1005],ans[1005][1005],book[1005][1005],flag=1;
inline void dfs1(int xx,int yy,int i,int j){
    if (xx<1||xx>n||yy<1||yy>n)return;
    book[xx][yy]=1;
    if (x[xx+1][yy]==i&&y[xx+1][yy]==j&&book[xx+1][yy]!=1){
        ans[xx+1][yy]=1;
        dfs1(xx+1,yy,i,j);
    }
    if (x[xx-1][yy]==i&&y[xx-1][yy]==j&&book[xx-1][yy]!=1){
        ans[xx-1][yy]=2;
        dfs1(xx-1,yy,i,j);
    }
    if (x[xx][yy+1]==i&&y[xx][yy+1]==j&&book[xx][yy+1]!=1){
        ans[xx][yy+1]=3;
        dfs1(xx,yy+1,i,j);
    }
    if (x[xx][yy-1]==i&&y[xx][yy-1]==j&&book[xx][yy-1]!=1){
        ans[xx][yy-1]=4;
        dfs1(xx,yy-1,i,j);
    }
    return;
}
inline void dfs2(int xx,int yy){
    if (xx<1||xx>n||yy<1||yy>n)return;
    book[xx][yy]=1;
    if (x[xx+1][yy]==-1&&book[xx+1][yy]!=1){
        ans[xx+1][yy]=1;
        dfs2(xx+1,yy);
    }
    if (x[xx-1][yy]==-1&&book[xx-1][yy]!=1){
        ans[xx-1][yy]=2;
        dfs2(xx-1,yy);
    }
    if (x[xx][yy+1]==-1&&book[xx][yy+1]!=1){
        ans[xx][yy+1]=3;
        dfs2(xx,yy+1);
    }
    if (x[xx][yy-1]==-1&&book[xx][yy-1]!=1){
        ans[xx][yy-1]=4;
        dfs2(xx,yy-1);
    }
    return;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d%d",&x[i][j],&y[i][j]);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (x[i][j]==i&&y[i][j]==j){
                ans[i][j]=5;
                dfs1(i,j,i,j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (x[i][j]==-1&&book[i][j]==0){
                if (x[i-1][j]==-1&&book[i][j]==0&&book[i-1][j]==0){
                    ans[i][j]=1,ans[i-1][j]=2;
                    book[i][j]=book[i-1][j]=1;
                    dfs2(i,j),dfs2(i-1,j);
                }
                else if (x[i+1][j]==-1&&book[i][j]==0&&book[i+1][j]==0){
                    ans[i][j]=2,ans[i+1][j]=1;
                    book[i][j]=book[i+1][j]=1;
                    dfs2(i,j),dfs2(i+1,j);
                }
                else if (x[i][j-1]==-1&&book[i][j]==0&&book[i][j-1]==0){
                    ans[i][j]=3,ans[i][j-1]=4;
                    book[i][j]=book[i][j-1]=1;
                    dfs2(i,j),dfs2(i,j-1);
                }
                else if (x[i][j+1]==-1&&book[i][j]==0&&book[i][j+1]==0){
                    ans[i][j]=4,ans[i][j+1]=3;
                    book[i][j]=book[i][j+1]=1;
                    dfs2(i,j),dfs2(i,j+1);
                }
                else flag=0;
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (book[i][j]==0)flag=0;
    if (flag==0)cout<<"INVALID"<<endl;
    else{
        cout<<"VALID"<<endl;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (ans[i][j]==1)putchar('U');
                if (ans[i][j]==2)putchar('D');
                if (ans[i][j]==3)putchar('L');
                if (ans[i][j]==4)putchar('R');
                if (ans[i][j]==5)putchar('X');
                if (j==n)puts("");
            }
        }
    }
    return 0;
}