#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[55][55];
int a[55][55],n,m;
void ssearch(int i,int j){
    if(i>n||j>m||i<=0||j<=0||a[i][j]) return;
    if(s[i][j]=='#') return;
    a[i][j]=1;
    ssearch(i+1,j);
    ssearch(i-1,j);
    ssearch(i,j+1);
    ssearch(i,j-1);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d\n",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",s[i]);
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                s[i][j]=s[i][j-1];
        int f=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[i][j]=='B'){
                    if(s[i+1][j]=='G'&&i<n||s[i-1][j]=='G'&&i>1||s[i][j+1]=='G'&&j<m||s[i][j-1]=='G'&&j>1) f=0;
                    if(s[i+1][j]=='.') s[i+1][j]='#';
                    if(s[i-1][j]=='.') s[i-1][j]='#';
                    if(s[i][j+1]=='.') s[i][j+1]='#';
                    if(s[i][j-1]=='.') s[i][j-1]='#';
                }
            }
        memset(a,0,sizeof(a));
        ssearch(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[i][j]=='G'){
                    if(a[i][j]==0) f=0;
                }
            }
        if(f) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}