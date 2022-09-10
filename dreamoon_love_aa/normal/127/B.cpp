#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int d[128];
int main(){
    int i,n,an=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        if(d[i])an++,d[i]^=1;
        else d[i]^=1;
    }
    printf("%d\n",an>>1);
    return 0;
}