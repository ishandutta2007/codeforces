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
#define SIZE 100010
int a[SIZE],d[SIZE];
vector<int>e[SIZE],an;
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    queue<int>qq;
    for(i=1;i<=n;i++)
        if(a[i]==0)qq.push(i);
    while(qq.size()){
        int x=qq.front();
        an.pb(x);
        qq.pop();
        d[x]++;
        for(i=0;i<e[x].size();i++){
            d[e[x][i]]++;
            if(d[e[x][i]]==a[e[x][i]])qq.push(e[x][i]);
        }
    }
    printf("%d\n",(int)an.size());
    for(i=0;i<an.size();i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    return 0;
}