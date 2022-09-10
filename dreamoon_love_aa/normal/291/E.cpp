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
#define SIZE 100010
string str[SIZE];
vector<int>e[SIZE];
char s[SIZE*3];
int last[SIZE*3];
int len,an;
void build(){
    int i,j;
    for(i=2;i<=len;i++){
        int now=last[i-1];
        while(now){
            if(s[now+1]==s[i]){
                last[i]=now+1;
                break;
            }
            now=last[now];
        }
        if(!now&&s[1]==s[i])now=last[i]=1;
    }
}
void go(int x,int now){
    int i,j;
    for(i=0;i<e[x].size();i++){
        int y=e[x][i];
        int next=now;
        for(j=0;j<str[y].size();j++){
            while(next){
                if(s[next+1]==str[y][j]){
                    next=next+1;
                    break;
                }
                else next=last[next];
            }
            if(!next&&s[1]==str[y][j])next=1;
            if(next==len)an++;
        }
        go(y,next);
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=2;i<=n;i++){
        int x;
        cin>>x>>str[i];
        e[x].pb(i);
    }
    scanf("%s",s+1);
    len=strlen(s+1);
    build();
    go(1,0);
    printf("%d\n",an);
    return 0;
}