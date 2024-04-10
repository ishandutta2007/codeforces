#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[1024][1024];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char input[1024];
int pos[26][2];
void go(int &sx,int &sy,int nx,int ny,int &k){
    int i;
    if(sx==nx){
        if(sy<ny){
            for(i=sy;i<ny;i++){
                if(!k){
                    printf("%d %d\n",sx,i);
                    exit(0);
                }
                if(s[sx][i]>='1'&&s[sx][i]<='9'){
                    k-=s[sx][i]-'0';
                    if(k<0){
                        printf("%d %d\n",sx,i);
                        exit(0);
                    }
                }
                else{
                    k--;
                }
            }
            sy=ny;
        }
        else{
            for(i=sy;i>ny;i--){
                if(!k){
                    printf("%d %d\n",sx,i);
                    exit(0);
                }
                if(s[sx][i]>='1'&&s[sx][i]<='9'){
                    k-=s[sx][i]-'0';
                    if(k<0){
                        printf("%d %d\n",sx,i);
                        exit(0);
                    }
                }
                else{
                    k--;
                }
            }
            sy=ny;
        }
    }
    else{
        if(sx<nx){
            for(i=sx;i<nx;i++){
                if(!k){
                    printf("%d %d\n",i,sy);
                    exit(0);
                }
                if(s[i][sy]>='1'&&s[i][sy]<='9'){
                    k-=s[i][sy]-'0';
                    if(k<0){
                        printf("%d %d\n",i,sy);
                        exit(0);
                    }
                }
                else{
                    k--;
                }
            }
            sx=nx;
        }
        else{
            for(i=sx;i>nx;i--){
                if(!k){
                    printf("%d %d\n",i,sy);
                    exit(0);
                }
                if(s[i][sy]>='1'&&s[i][sy]<='9'){
                    k-=s[i][sy]-'0';
                    if(k<0){
                        printf("%d %d\n",i,sy);
                        exit(0);
                    }
                }
                else{
                    k--;
                }
            }
            sx=nx;
        }
    }
}
int main(){
    int i,j,k,n,m,sx,sy,ex,ey;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s[i][j]>='a'&&s[i][j]<='z'){
                pos[s[i][j]-'a'][0]=i;
                pos[s[i][j]-'a'][1]=j;
            }

    scanf("%d%d%s%d%d",&sx,&sy,input,&ex,&ey);

    for(i=0;input[i];i++){
        go(sx,sy,pos[input[i]-'a'][0],pos[input[i]-'a'][1],k);
    }
    go(sx,sy,ex,ey,k);
    printf("%d %d\n",ex,ey);
    return 0;
}