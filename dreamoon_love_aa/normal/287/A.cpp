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
char s[4][6];
bool check(int x,int y){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            if(s[x+i][y+j]!=s[x][y])return 0;
    return 1;
}
bool check(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(check(i,j))return 1;
    return 0;
}
void over(){
    puts("YES");
    exit(0);
}
int main(){
    int i,j,k,n;
    for(i=0;i<4;i++)scanf("%s",s[i]);
    if(check())over();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            char c=s[i][j];
            s[i][j]='#';
            if(check())over();
            s[i][j]='.';
            if(check())over();
            s[i][j]=c;
        }
    }
    puts("NO");
    return 0;
}