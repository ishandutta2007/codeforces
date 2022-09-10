
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
    int i,j,k,n;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++){
            int x;
            scanf("%d",&x);
            if(x==1){
                printf("%d\n",abs(i-2)+abs(j-2));
                return 0;
            }
        }
    return 0;
}