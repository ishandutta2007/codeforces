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
char s1[111],s2[111];
int main(){
    int i,j,k=0,n;
    scanf("%s%s",s1,s2);
    for(i=0;s2[i];i++){
        if(s1[k]==s2[i])k++;
    }
    printf("%d\n",k+1);
    return 0;
}