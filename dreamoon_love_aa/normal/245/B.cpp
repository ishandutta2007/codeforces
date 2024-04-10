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
char s[55];
int main(){
    int i,j,k,n;
    gets(s);
    if(strncmp("ftp",s,3)==0){
        for(i=4;;i++){
            if(s[i]=='r'&&s[i+1]=='u')break;
        }
        s[i]=0;
        printf("ftp://%s.ru",s+3);
        if(s[i+2])printf("/%s",s+i+2);
    }
    else{
        for(i=5;;i++){
            if(s[i]=='r'&&s[i+1]=='u')break;
        }
        s[i]=0;
        printf("http://%s.ru",s+4);
        if(s[i+2])printf("/%s",s+i+2);
    }
    puts("");
    return 0;
}