#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 100000
using namespace std;
int f[1005][1005],nxt[1005][105];
char s[1005],t[1005];
int q,n,m;
inline bool check(int now){
    for (int i=0;i<=401;i++)
        for (int j=0;j<=401;j++)
            f[i][j]=inf;
    f[0][now]=nxt[0][t[now]-'a'];
    for (int i=now+1;i<=n;i++)
        if (f[0][i-1]<inf)f[0][i]=nxt[f[0][i-1]+1][t[i]-'a'];
    f[1][now-1]=nxt[0][t[1]-'a'];
    for (int i=2;i<now;i++)
        if (f[i-1][now-1]<inf)f[i][now-1]=nxt[f[i-1][now-1]+1][t[i]-'a'];
    for (int i=1;i<now;i++) 
        for (int j=now;j<=n;j++){
            if (f[i-1][j]<inf){
                if (nxt[f[i-1][j]+1][t[i]-'a']<=m)
                    f[i][j]=min(f[i][j],nxt[f[i-1][j]+1][t[i]-'a']);
            }
            if (f[i][j-1]<inf){
                if (nxt[f[i][j-1]+1][t[j]-'a']<=m)
                    f[i][j]=min(f[i][j],nxt[f[i][j-1]+1][t[j]-'a']);
            }
        }
    int ans=f[now-1][n];
    if (ans<=m)return 1;
    return 0;
}
int main(){
    cin>>q;
    while(q--){
        scanf("%s%s",s+1,t+1);
        m=strlen(s+1),n=strlen(t+1);
        for (int i=0;i<=401;i++)
            for (int j=0;j<26;j++)
                nxt[i][j]=inf;
        for (int i=m;i>=0;i--){
            for (int j=0;j<26;j++)nxt[i][j]=nxt[i+1][j];
            if (i!=0)nxt[i][s[i]-'a']=i;
        }
        int flag=0;
        if (n==1){
            for (int i=1;i<=m;i++)
                if (s[i]==t[n])flag=1;
        }
        for (int i=2;i<=n;i++){ 
            if (check(i))flag=1;
        } 
        if (flag==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}