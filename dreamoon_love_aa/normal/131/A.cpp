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
    int i,j,k,big=0;
    char s[128];
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]>='A'&&s[i]<='Z')big++;
    }
    if(big==i||(big==i-1&&s[0]>='a'&&s[0]<='z')){
        if(big==i){
            for(i=0;s[i];i++)putchar(s[i]-'A'+'a');
        }
        else{
            putchar(s[0]-'a'+'A');
            for(i=1;s[i];i++)putchar(s[i]-'A'+'a');
        }
        puts("");
    }
    else puts(s);
    return 0;
}