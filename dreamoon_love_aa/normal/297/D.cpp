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
#define SIZE 1024
int an[SIZE][SIZE],used[SIZE][SIZE],n,m;
char e1[SIZE][SIZE],e2[SIZE][SIZE];
void fill(int x,int y){
    used[x][y]=1;
    int d[2]={};
    if(x){
        if(used[x-1][y]){
            if(e2[x-1][y]=='N')d[2-an[x-1][y]]++;
            else d[an[x-1][y]-1]++;
        }
    }
    if(y){
        if(used[x][y-1]){
            if(e1[x][y-1]=='N')d[2-an[x][y-1]]++;
            else d[an[x][y-1]-1]++;
        }
    }
    if(x!=n-1){
        if(used[x+1][y]){
            if(e2[x][y]=='N')d[2-an[x+1][y]]++;
            else d[an[x+1][y]-1]++;
        }
    }
    if(y!=m-1){
        if(used[x][y+1]){
            if(e1[x][y]=='N')d[2-an[x][y+1]]++;
            else d[an[x][y+1]-1]++;
        }    }
    if(d[0]>=d[1])an[x][y]=1;
    else an[x][y]=2;
}
int main(){
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    gets(e1[0]);
    for(i=0;i<2*n-1;i++){
        if(i%2==0){
            gets(e1[i/2]);
        }
        else{
            gets(e2[i/2]);
        }
    }
    if(k==1){
        int cnt1=0,cnt2=0;
        for(i=0;i<n;i++)
            for(j=0;j<m-1;j++){
                if(e1[i][j]=='E')cnt1++;
                else cnt2++;
            }
        for(i=0;i<n-1;i++)
            for(j=0;j<m;j++){
                if(e1[i][j]=='E')cnt1++;
                else cnt2++;
            }
        if(cnt1*4>=(cnt1+cnt2)*3){
            puts("YES");
            for(i=0;i<n;i++,puts(""))
                for(j=0;j<m;j++){
                    if(j)printf(" ");
                    printf("1");
                }
        }
        else puts("NO");
    }
    else{
        puts("YES");
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                if(j%2==0||i==0||(i%2==0&&j==m-1))fill(i,j);
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                if(!used[i][j])fill(i,j);
            }
        for(i=0;i<n;i++,puts(""))
            for(j=0;j<m;j++){
                if(j)printf(" ");
                printf("%d",an[i][j]);
            }
    }
    return 0;
}