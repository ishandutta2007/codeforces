#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100010
char s[SIZE];
int main(){
    int i=1,j,n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    while(k){
        while(1){
            if(s[i+1]==0){
                puts(s+1);
                return 0;
            }
            if(s[i]=='4'&&s[i+1]=='7'){
                if(i&1){
                    s[i+1]='4';
                    i++;
                    break;
                }
                else{
                    s[i]='7';
                    if(s[i-1]=='4'){
                        if(!(k&1)){
                            s[i]='4';
                        }
                        puts(s+1);
                        return 0;
                    }
                    else{
                        i++;
                        break;
                    }
                }
            }
            else i++;
        }
        k--;
    }
    puts(s+1);
    return 0;
}