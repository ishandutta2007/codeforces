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
    char s[8];
    int i,j,k;
    scanf("%s%d",s,&i);
    if((strcmp(s,"front")==0?1:0)^(i-1))puts("L");
    else puts("R");
    return 0;
}