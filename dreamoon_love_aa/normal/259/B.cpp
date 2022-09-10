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
int a[3][3];
int main(){
    int i,j,k,n;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)cin>>a[i][j];
    for(i=1;i<=100000;i++){
        a[0][0]=i;
        a[1][1]=a[0][0]+a[0][1]+a[0][2]-a[1][0]-a[1][2];
        a[2][2]=a[0][0]+a[0][1]+a[0][2]-a[2][0]-a[2][1];
        if(a[0][0]+a[1][1]+a[2][2]==a[0][0]+a[1][0]+a[2][0]){
            for(i=0;i<3;i++,puts(""))
                for(j=0;j<3;j++){
                    if(j)printf(" ");
                    printf("%d",a[i][j]);
                }
            return 0;
        }
    }
    return 0;
}