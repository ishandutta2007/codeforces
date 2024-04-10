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
bitset<50>a[50],b[50];
int main(){
    int i,j,k,na,nb,ma,mb;
    cin>>na>>ma;
    for(i=0;i<na;i++){
        char s[111];
        scanf("%s",s);
        for(j=0;j<ma;j++)
            if(s[j]=='1')a[i][j]=1;
    }
    cin>>nb>>mb;
    for(i=0;i<nb;i++){
        char s[111];
        scanf("%s",s);
        for(j=0;j<mb;j++)
            if(s[j]=='1')b[i][j]=1;
    }
    int dx=0,dy=0,ha=0;
    for(i=-49;i<50;i++)
        for(j=-49;j<50;j++){
            int now=0;
            for(k=0;k<na;k++){
                if(k+i>=0&&k+i<nb){
                    if(j<0)now+=(a[k]&(b[k+i]<<(-j))).count();
                    else now+=(a[k]&(b[k+i]>>j)).count();
                }
            }
            if(now>ha){
                ha=now;
                dx=i;dy=j;
            }
        }
    printf("%d %d\n",dx,dy);
    return 0;
}