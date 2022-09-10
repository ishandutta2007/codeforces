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
char s[256],stack[256*256][256];
int sn;
int main(){
    int i,j,k,n;
    cin>>n;
    while(n--){
        scanf("%s",s);
        if(s[0]=='p'){
            printf("/");
            for(i=0;i<sn;i++)printf("%s/",stack[i]);
            puts("");
        }
        else{
            scanf("%s",s);
            if(s[0]=='/'){
                sn=0;
                i=1;
            }
            else i=0;
            while(s[i]){
                if(s[i]=='.'){
                    i+=2;
                    if(sn>0)sn--;
                }
                else{
                    for(j=0;s[i+j]&&s[i+j]!='/';j++)stack[sn][j]=s[i+j];
                    stack[sn][j]=0;
                    sn++;
                    i+=j;
                }
                if(!s[i])break;
                else i++;
            }
        }
    }
    return 0;
}