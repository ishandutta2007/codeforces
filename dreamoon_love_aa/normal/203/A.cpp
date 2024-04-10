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
void AC(){puts("YES");}
int main(){
    int i,j,k,x,a,b,da,db,t;
    scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
    for(i=0;i<t;i++)
        for(j=0;j<t;j++)
            if(x==a-da*i+b-db*j){
                AC();
                return 0;
            }
    for(i=0;i<t;i++){
        if(x==a-da*i||x==b-db*i){
            AC();
            return 0;
        }
    }
    if(x==0){
        AC();
        return 0;
    }
    puts("NO");
    return 0;
}