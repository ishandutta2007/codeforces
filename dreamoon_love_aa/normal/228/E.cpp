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
#define SIZE 100
bitset<5050>d[SIZE],need;
bitset<SIZE>state[SIZE],used;
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)state[i][i]=1;
    for(i=0;i<m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        if(!v)need[i]=1;
        x--,y--;
        d[x][i]=1;
        d[y][i]=1;
    }
    int now=0;
    for(i=0;i<m&&now<n;i++){
        for(j=now;j<n&&!d[j][i];j++);
        if(j>=n){
            if(need[i]){
                puts("Impossible");
                return 0;
            }
            continue;
        }
        if(j!=now){
            swap(d[j],d[now]);
            swap(state[j],state[now]);
        }
        for(j=now+1;j<n;j++){
            if(d[j][i]){
                d[j]^=d[now];
                state[j]^=state[now];
            }
        }
        if(need[i]){
            need^=d[now];
            used^=state[now];
        }
        now++;
    }
    for(;i<m;i++)
        if(need[i]){
            puts("Impossible");
            return 0;
        }
    printf("%d\n",used.count());
    bool flag=1;
    for(i=0;i<n;i++){
        if(used[i]){
            if(!flag)printf(" ");
            else flag=0;
            printf("%d",i+1);
        }
    }
    puts("");
    return 0;
}