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
char s[1000100];
int main(){
    int i,j,k,n,an=0;
    gets(s+1);
    s[0]='0';
    for(i=0;s[i];i++);
    for(i--;i>=0;i--){
        if(s[i]=='1'){
            if(i==0||s[i-1]=='0')an++;
            else{
                while(s[i]=='1')i--;
                s[i++]='1';
                an++;
            }
        }
    }
    printf("%d\n",an);
    return 0;
}