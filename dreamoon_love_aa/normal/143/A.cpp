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
int main(){
    int i,j,k,l,n,r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
            for(k=1;k<=9;k++)
                for(l=1;l<=9;l++){
                    if(i==j||j==k||k==l||i==k||i==l||j==l)continue;
                    if(i+l==d1&&j+k==d2&&i+j==r1&&k+l==r2&&i+k==c1&&j+l==c2){
                        printf("%d %d\n%d %d\n",i,j,k,l);
                        return 0;
                    }
                }
    puts("-1");
    return 0;
}