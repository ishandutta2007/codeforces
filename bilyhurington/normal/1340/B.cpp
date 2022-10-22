/*
 * @Author: BilyHurington
 * @Date: 2020-04-23 22:45:12
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-23 23:22:13
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,k,num[10][10]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int cha(int *a,int *b){
    int cnt=0;
    for(int i=0;i<7;i++){
        if(a[i]>b[i]) return -1;
        if(a[i]^b[i]) cnt++;
    }
    return cnt;
}
bool keda[2010][2010];
int st[2010][10];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        char ch;
        for(int j=0;j<7;j++) scanf(" %c",&ch),st[i][j]=ch-'0';
    }
    keda[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=k;j++){
            if(!keda[i+1][j]) continue;
            for(int l=0;l<=9;l++){
                int pt=cha(st[i],num[l]);
                if(pt==-1) continue;
                keda[i][j+pt]=1; 
            }
        }
    }
    if(!keda[1][k]){printf("-1");return 0;}
    for(int i=1;i<=n;i++){
        for(int l=9;l>=0;l--){
            int pt=cha(st[i],num[l]);
            if(pt==-1||k<pt) continue;
            if(keda[i+1][k-pt]){printf("%d",l);k-=pt;break;}
        }
    }
    return 0;
}