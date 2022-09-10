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
#define SIZE 100010
char s1[SIZE],s2[SIZE];
int main(){
    int i,j,k,n;
    scanf("%s%s",s1,s2);
    if(strlen(s1)!=strlen(s2)){
        puts("NO");
        return 0;
    }
    vector<int>d;
    for(i=0;s1[i];i++){
        if(s1[i]!=s2[i])d.pb(i);
    }
    if(d.size()!=2){
        puts("NO");
        return 0;
    }
    if(s1[d[0]]!=s2[d[1]]||s1[d[1]]!=s2[d[0]]){
        puts("NO");
    }
    else puts("YES");
    return 0;
}