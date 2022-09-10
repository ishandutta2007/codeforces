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
    int i,j,k,n=305;
    printf("%d\n",n);
    printf("1 1000000\n");
    int x=300000,tmp=303;
    for(i=2;i<n;i++){
        printf("%d %d\n",x,tmp);
        x+=tmp;
        tmp--;
        x+=tmp;
    }
    printf("1000000 1000000\n");
    return 0;
}