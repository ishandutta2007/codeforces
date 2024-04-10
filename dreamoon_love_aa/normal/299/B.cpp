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
char s[300010];
int main(){
    int i,j=0,k=0,K,n;
    scanf("%d%d%s",&n,&K,s);
    for(i=0;i<n;i++){
        if(s[i]=='#'){
            k++;
            j=max(j,k);
        }
        else k=0;
    }
    if(s[n-1]=='#'||j>=K)puts("NO");
    else puts("YES");
    return 0;
}