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
char s[2][2001000],res[2];
int d[2][2];
int main(){
    int i,j,k,n;
    cin>>n;
    scanf("%s%s",s[0],s[1]);
    for(i=0;i<n*2;i++)
        d[s[0][i]-'0'][s[1][i]-'0']++;
    for(i=0;i<n;i++){
        if(d[1][1]){
            d[1][1]--;
            res[0]=1;
        }
        else if(d[1][0]){
            d[1][0]--;
            res[0]=1;
        }
        else if(d[0][1]){
            d[0][1]--;
            res[0]=0;
        }
        else{
            d[0][0]--;
            res[0]=0;
        }

        if(d[1][1]){
            d[1][1]--;
            res[1]=1;
        }
        else if(d[0][1]){
            d[0][1]--;
            res[1]=1;
        }
        else if(d[1][0]){
            d[1][0]--;
            res[1]=0;
        }
        else{
            d[0][0]--;
            res[1]=0;
        }
        if(res[0]==1&&res[1]==0){
            puts("First");
            return 0;
        }
        if(res[0]==0&&res[1]==1){
            puts("Second");
            return 0;
        }
    }
    puts("Draw");
    return 0;
}