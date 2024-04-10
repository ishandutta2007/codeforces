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
char s[1234567],qq[1234567];
int qn,have;
int main(){
    int i,j,k,n;
    while(gets(s)!=NULL){
        for(i=0;s[i]==' ';i++);
        if(s[i]=='#'){
            if(have){
                qq[qn]=0;
                puts(qq);
                have=0;
            }
            puts(s);
            qn=0;
        }
        else{
            have=1;
            for(i=0;s[i];i++){
                if(s[i]!=' ')qq[qn++]=s[i];
            }
        }
    }
    if(have){
        qq[qn]=0;
        puts(qq);
    }
    return 0;
}