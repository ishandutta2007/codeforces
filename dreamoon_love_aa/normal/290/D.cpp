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
char s[128];
int main(){
    int i,j,k,n;
    scanf("%s%d",s,&n);
    for(i=0;s[i];i++)
        if(s[i]>='A'&&s[i]<='Z')s[i]-='A'-'a';
    for(i=0;s[i];i++)
        if(s[i]-'a'<n)s[i]+='A'-'a';
    puts(s);
    return 0;
}