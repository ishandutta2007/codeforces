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
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",n&1^1);
    }
    return 0;
}