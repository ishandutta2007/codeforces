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
void put(int x){while(x--)putchar(' ');}
int main(){
    char s[1024];
    int i,j,now=0;
    gets(s);
    for(i=0;s[i];i=j){
        if(s[i+1]=='/'){
            now--;
            put(now<<1);
        }
        else{
            put(now<<1);
            now++;
        }
        for(j=i;s[j]!='>';j++)putchar(s[j]);
        puts(">");
        j++;
    }
    return 0;
}