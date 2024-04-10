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
char s[100010];
int main(){
    int i,j,k,n;
    gets(s);
    for(i=0;s[i];i=j){
        if(s[i]=='\"'){
            printf("<");
            for(j=i+1;s[j]!='\"';j++)printf("%c",s[j]);
            puts(">");
            j++;
        }
        else if(s[i]==' '){
            j=i+1;
        }
        else{
            printf("<");
            for(j=i;s[j]&&s[j]!=' '&&s[j]!='\"';j++)printf("%c",s[j]);
            puts(">");
        }
    }
    return 0;
}