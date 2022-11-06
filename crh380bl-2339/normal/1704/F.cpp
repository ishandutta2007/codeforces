#include<bits/stdc++.h>
#define N 500005
using namespace std;
int f[N];
bool vis[N];
char s[N];
int DFS(int n) {
    if (n <= 1)return 0;
    if(vis[n])return f[n];
    vis[n]=1;
    int i;
    set<int>bo;
    bo.clear();
    for (i = 0; i <= n - 2 - i; ++i) {
        bo.insert(DFS(i)^DFS(n - 2 - i));
    }
    for (i = 0; bo.find(i)!=bo.end(); ++i);
    return f[n] = i;
}
void work(){
    int n,i,j;
    scanf("%d",&n);
    scanf("%s",s+1);
    int R=0,B=0;
    for(i=1;i<=n;++i){
        if(s[i]=='R')++R;
        else ++B;
    }
    if(R>B){
        puts("Alice");
        return;
    }
    if(B>R){
        puts("Bob");
        return;
    }
    int tmp=0,ans=0;
    for(i=1;i<=n;++i){
        if(i==1||s[i]!=s[i-1]){
            ++tmp;
        }
        else{
            ans^=f[tmp];
            tmp=1;
        }
    }
    ans^=f[tmp];
    if(ans)puts("Alice");
    else puts("Bob");
}
int main() {
    int i;
    for (i = 0; i <= 200; ++i)DFS(i);
    for(i=201;i<=500000;++i)f[i]=f[i-34];
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}