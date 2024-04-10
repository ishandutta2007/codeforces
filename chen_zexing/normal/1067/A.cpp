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
long long mod=998244353,pre[100005][200][3];
int a[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    pre[0][0][1]=1;
    for(int i=1;i<=200;i++) pre[0][i][1]=1;
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            pre[i][a[i]][2]=pre[i-1][a[i]-1][0]+pre[i-1][a[i]-1][1]+pre[i-1][a[i]-1][2],pre[i][a[i]][2]%=mod;
            pre[i][a[i]][1]=(pre[i-1][a[i]][0]-pre[i-1][a[i]-1][0]+pre[i-1][a[i]][1]-pre[i-1][a[i]-1][1]+pre[i-1][a[i]][2]-pre[i-1][a[i]-1][2])%mod+mod,pre[i][a[i]][1]%=mod;
            pre[i][a[i]][0]=((pre[i-1][200][0]-pre[i-1][a[i]][0]+pre[i-1][200][1]-pre[i-1][a[i]][1])%mod+mod)%mod;
            for(int j=1;j<=200;j++)
                if(a[i]!=j)
                    pre[i][j][0]=pre[i][j][1]=pre[i][j][2]=0;
        }
        else{
            for(int j=1;j<=200;j++){
                a[i]=j;
                pre[i][a[i]][2]=pre[i-1][a[i]-1][0]+pre[i-1][a[i]-1][1]+pre[i-1][a[i]-1][2],pre[i][a[i]][2]%=mod;
                pre[i][a[i]][1]=(pre[i-1][a[i]][0]-pre[i-1][a[i]-1][0]+pre[i-1][a[i]][1]-pre[i-1][a[i]-1][1]+pre[i-1][a[i]][2]-pre[i-1][a[i]-1][2])%mod+mod,pre[i][a[i]][1]%=mod;
                pre[i][a[i]][0]=((pre[i-1][200][0]-pre[i-1][a[i]][0]+pre[i-1][200][1]-pre[i-1][a[i]][1])%mod+mod)%mod;
            }
        }
        for(int j=0;j<3;j++) pre[i][0][j]=0;
        for(int j=1;j<=200;j++)
            for(int k=0;k<3;k++)
                pre[i][j][k]=(pre[i][j-1][k]+pre[i][j][k])%mod;
    }
    cout<<(pre[n][200][0]+pre[n][200][1])%mod<<endl;
    return 0;
}