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
#include<queue>
#define pb push_back
using namespace std;
#define MAX 1000000000
char s[2][100020];
int mi[200040];
bool used[200040];
bool fresh(int &x,int v){
    if(x>v){
        x=v;
        return 1;
    }
    return 0;
}
int main(){
    int i,j,k,n;
    bool flag=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<2;i++)scanf("%s",s[i]);
    for(i=0;i<n*2;i++)mi[i]=MAX;
    queue<int>qq;
    qq.push(0);
    mi[0]=0;
    while(!qq.empty()){
        int x=qq.front();qq.pop();
        used[x]=0;
        if((x>>1)+k>=n){
            flag=1;
            break;
        }
        if(s[(x&1)^1][(x>>1)+k]=='-'&&fresh(mi[(x+k*2)^1],mi[x]+1)){
            if(!used[(x+k*2)^1]){
                used[(x+k*2)^1]=1;
                qq.push((x+k*2)^1);
            }
        }
        if(s[x&1][(x>>1)+1]=='-'&&fresh(mi[x+2],mi[x]+1)){
            if(!used[x+2]){
                used[x+2]=1;
                qq.push(x+2);
            }
        }
        if((x>>1)>0&&s[x&1][(x>>1)-1]=='-'&&mi[x]+1<=(x>>1)-1&&fresh(mi[x-2],mi[x]+1)){
            if(!used[x-2]){
                used[x-2]=1;
                qq.push(x-2);
            }
        }
    }
    puts(flag?"YES":"NO");
    return 0;
}