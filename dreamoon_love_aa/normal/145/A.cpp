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
#define SIZE 100020
char s1[SIZE],s2[SIZE];
int aa,bb;
int main(){
    int i,j,k,n,len;
    scanf("%s%s",s1,s2);
    len=strlen(s1);
    for(i=0;i<len;i++){
        if(s1[i]=='4'&&s2[i]=='7')aa++;
        if(s1[i]=='7'&&s2[i]=='4')bb++;
    }
    printf("%d\n",max(aa,bb));
    return 0;
}