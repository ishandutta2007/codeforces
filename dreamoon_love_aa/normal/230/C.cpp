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
char s[110][10010];
int d1[110][10010],d2[110][10010],an[10010];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
        for(j=0;j<m;j++)
            if(s[i][j]=='1')break;
        if(j==m){
            puts("-1");
            return 0;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)d1[i][j]=d2[i][j]=100000000;
    for(i=0;i<n;i++){
        int now=1000000;
        for(j=0;j<m*2;j++){
            now++;
            if(s[i][j%m]=='1')now=0;
            d1[i][j%m]=min(d1[i][j%m],now);
        }
        now=1000000;
        for(j=m*2-1;j>=0;j--){
            now++;
            if(s[i][j%m]=='1')now=0;
            d2[i][j%m]=min(d2[i][j%m],now);
        }
        for(j=0;j<m;j++)an[j]+=min(d1[i][j],d2[i][j]);
    }
    int res=1000000000;
    for(i=0;i<m;i++)res=min(res,an[i]);
    cout<<res<<endl;
    return 0;
}