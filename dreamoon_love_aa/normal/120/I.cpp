#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
int digit[10][7]={{1,1,1,1,1,1,0}
                ,{0,1,1,0,0,0,0}
                ,{1,1,0,1,1,0,1}
                ,{1,1,1,1,0,0,1}
                ,{0,1,1,0,0,1,1}
                ,{1,0,1,1,0,1,1}
                ,{1,0,1,1,1,1,1}
                ,{1,1,1,0,0,0,0}
                ,{1,1,1,1,1,1,1}
                ,{1,1,1,1,0,1,1}};
int sum[10];
int AND[10][10];
int dp1[200000],dp2[200000],B;
int haha(int x,int y){
    int an=0;
    for(int i=0;i<7;i++)an+=digit[x][i]&digit[y][i];
    return an;
}
char s[200020];
int pre(int x){
    if(x<0)return 0;
    return dp1[x];
}
int fin(int x){
    if(x<0)return 0;
    return dp2[x];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)AND[i][j]=haha(i,j);
        for(j=0;j<7;j++)sum[i]+=digit[i][j];
    }
    gets(s);
    n=strlen(s);
    for(i=0;i<n;i++)s[i]-='0';
    k=n/2;
    for(i=0;i<k;i++){
        dp1[i]=AND[s[i]][s[i+k]];
        dp2[i]=sum[s[i]];
        if(i){
            dp1[i]+=dp1[i-1];
            dp2[i]+=dp2[i-1];
        }
    }
    B=dp1[k-1];
    for(i=n-1;i>=0;i--){
        if(i>=k){
            for(j=s[i]+1;j<10;j++){
                if(pre(i-k-1)+AND[s[i-k]][j]+dp2[k-1]-fin(i-k)>B)break;
            }
        }
        else{
            for(j=s[i]+1;j<10;j++){
                if(fin(i-1)+sum[j]+7*(k-i-1)>B)break;
            }
        }
        if(j<10){
            s[i]=j;
            break;
        }
    }
    if(i<0)puts("-1");
    else{
        if(i<k){
            dp2[i]=sum[s[i]];
            if(i){
                dp2[i]+=dp2[i-1];
            }
        }
        else{
            dp1[i-k]=AND[s[i]][s[i-k]];
            if(i-k){
                dp1[i-k]+=dp1[i-k-1];
            }
        }
        for(i++;i<n;i++){
            for(j=0;j<10;j++){
                if(i<k){
                    if(fin(i-1)+sum[j]+7*(k-i-1)>B)break;
                }
                else{
                    if(pre(i-k-1)+AND[s[i-k]][j]+dp2[k-1]-fin(i-k)>B)break;
                }
            }
            s[i]=j;
            if(i<k){
                dp2[i]=sum[s[i]];
                if(i){
                    dp2[i]+=dp2[i-1];
                }
            }
            else{
                dp1[i-k]=AND[s[i]][s[i-k]];
                if(i-k){
                    dp1[i-k]+=dp1[i-k-1];
                }
            }
        }
        for(i=0;i<n;i++)s[i]+='0';
        puts(s);
    }
    return 0;
}