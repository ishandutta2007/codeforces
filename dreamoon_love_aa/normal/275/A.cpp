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
int a[6][6];
int dx[5]={1,0,-1,0,0};
int dy[5]={0,1,0,-1,0};
int main(){
    int i,j,k,n;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++){
            cin>>k;
            if(k&1){
                for(k=0;k<5;k++)a[i+dx[k]][j+dy[k]]^=1;
            }
        }
    for(i=1;i<=3;i++,puts("")){
        for(j=1;j<=3;j++){
            printf("%d",1-a[i][j]);
        }
    }
    return 0;
}