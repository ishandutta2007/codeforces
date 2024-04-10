/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-20 00:57:45
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
int n;
bool kd[20][20];
vector<long long> f[1<<14][14];
int main(){
    char ch;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf(" %c",&ch),kd[i][j]=ch-'0';
    }
    long long ans=0;
    for(int i=1;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cnt++;
        }
        for(int j=0;j<n;j++) if(i&(1<<j)) f[i][j].resize(1<<(cnt-1)+1);
    }
    for(int i=0;i<n;i++) f[(1<<i)][i][0]=1;
    for(int i=1;i<(1<<n)-1;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cnt++;
        }
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))) continue;
            for(int k=0;k<n;k++){
                if(i&(1<<k)) continue;
                if(kd[j][k]){
                    for(int now=0;now<(1<<cnt);now+=2){
                        f[i^(1<<k)][k][now^(1<<cnt)]+=f[i][j][now];
                    }    
                }
                else{
                    for(int now=0;now<(1<<cnt);now+=2){
                        f[i^(1<<k)][k][now]+=f[i][j][now];
                    }    
                }
            }
        }
    }
    for(int i=0;i<(1<<(n-1));i++){
        long long ans=0;
        for(int j=0;j<n;j++){
            ans+=f[(1<<n)-1][j][i*2];
        }
        printf("%lld ",ans);
    }
    return 0;
}