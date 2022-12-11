#include<bits/stdc++.h>
using namespace std;
const int N=500;
int T,ls,lt,mx[N],g[N];char s[N],t[N];
bool calc(int x){
    memset(mx,-1,sizeof(int)*(lt+1));mx[0]=x;
    for(int i=1;i<=ls;i++){
        for(int j=0;j<=x;j++)g[j]=mx[j]+(mx[j]<lt&&s[i]==t[mx[j]+1]);
        for(int j=0;j<x;j++)g[j+1]=max(g[j+1],s[i]==t[j+1]?mx[j]:0);
        for(int j=0;j<=x;j++)mx[j]=g[j];
    }
    return mx[x]==lt;
}
void solve(){
    scanf("%s%s",s+1,t+1);
    ls=strlen(s+1),lt=strlen(t+1);
    for(int i=1,j=0;i<=ls;i++){
        if(j<lt&&s[i]==t[j+1])j++;
        if(j==lt){puts("YES");return;}
    }
    memset(mx,-1,sizeof(mx));mx[0]=0;
    for(int i=1;i<lt;i++)if(calc(i)){puts("YES");return;}
    puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}