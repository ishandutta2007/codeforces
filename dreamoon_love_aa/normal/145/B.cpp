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
int cnt[4];
char an[2000010];
int main(){
    int i,j,k,n;
    for(i=0;i<4;i++)scanf("%d",&cnt[i]);
    if(cnt[2]==cnt[3]){
        if(cnt[0]<=cnt[2]&&cnt[1]<=cnt[2])puts("-1");
        else if(cnt[0]<cnt[2]||cnt[1]<cnt[2])puts("-1");
        else if(cnt[0]==cnt[2]){
            for(i=0;i<cnt[2];i++)printf("74");
            cnt[1]-=cnt[2];
            for(i=0;i<cnt[1];i++)putchar('7');
        }
        else{
            for(i=cnt[2];i<cnt[0];i++)putchar('4');
            for(i=1;i<cnt[2];i++)printf("74");
            for(i=cnt[2];i<=cnt[1];i++)putchar('7');
            putchar('4');
        }
    }
    else if(cnt[2]+1==cnt[3]){
        if(cnt[0]<cnt[3]||cnt[1]<cnt[3])puts("-1");
        else{
            for(i=0;i<cnt[3];i++){
                an[i*2]='7';
                an[i*2+1]='4';
            }
            putchar(an[0]);
            for(i=cnt[3];i<cnt[0];i++)putchar('4');
            for(i=1;i<cnt[3]*2-1;i++)putchar(an[i]);
            for(i=cnt[3];i<cnt[1];i++)putchar('7');
            putchar(an[cnt[3]*2-1]);
        }
    }
    else if(cnt[3]+1==cnt[2]){
        if(cnt[0]<cnt[2]||cnt[1]<cnt[2])puts("-1");
        else{
            for(i=0;i<cnt[2];i++){
                an[i*2]='4';
                an[i*2+1]='7';
            }
            putchar(an[0]);
            for(i=cnt[2];i<cnt[0];i++)putchar('4');
            for(i=1;i<cnt[2]*2-1;i++)putchar(an[i]);
            for(i=cnt[2];i<cnt[1];i++)putchar('7');
            putchar(an[cnt[2]*2-1]);
        }
    }
    else puts("-1");
    return 0;
}