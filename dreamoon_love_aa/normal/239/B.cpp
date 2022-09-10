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
char s[1010],tmp[110];
int main(){
    int i,j,k,n,q,ll,rr;
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    strcpy(tmp,s);
    while(q--){
        int d[10]={},used[110]={};
        scanf("%d%d",&ll,&rr);
        ll--;rr--;
        int dd=1,now=ll;
        while(now>=ll&&now<=rr){
            int last=now;
            if(used[now])now+=dd;
            else if(s[now]=='>'){
                dd=1;
                now++;
                while(now<=rr&&used[now])now++;
                if(s[now]=='>'||s[now]=='<')used[last]=1;
            }
            else if(s[now]=='<'){
                dd=-1;
                now--;
                while(now>=ll&&used[now])now--;
                if(s[now]=='>'||s[now]=='<')used[last]=1;
            }
            else{
                d[s[now]-'0']++;
                if(s[now]=='0')used[now]=1;
                else s[now]--;
                now+=dd;
            }
        }
        for(i=0;i<10;i++){
            if(i)printf(" ");
            printf("%d",d[i]);
        }
        puts("");
        strcpy(s,tmp);
    }
    return 0;
}