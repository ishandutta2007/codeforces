#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
vector <int> v[5005];
int t[5005],c[5005],tar[5005];
int dfs(int x)
{
    int f=0;
    if(v[x].size()) c[x]=1;
    for(int i=0;i<v[x].size();i++) {
        if(tar[v[x][i]]) {
            f = 1;
            break;
        }
        if(c[v[x][i]])
            break;
        if(dfs(v[x][i])) {
            f = 1;
            break;
        }
    }
    return f;
}
int main() {
    int n,m,f=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        if(a<b) t[i]=1;
        else t[i]=2;
    }
    for(int i=1;i<=n;i++) {
        memset(c, 0, sizeof(c));
        memset(tar,0,sizeof(tar));
        tar[i]=1;
        if (dfs(i)) {
            f = 1;
            break;
        }
    }
    if(f==0)
    {
        cout<<1<<endl;
        for(int i=1;i<=m;i++) printf("1 ");
        printf("\n");
    }
    else{
        cout<<2<<endl;
        for(int i=1;i<=m;i++) printf("%d ",t[i]);
        printf("\n");
    }
}