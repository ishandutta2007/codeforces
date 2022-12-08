#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
const int mod =1e9+9;
int f[1001][1001][11],n,m,ch[1001][4],val[1001],fail[1001],mx,tot;
string ss;
void add(int &x,int y) {
    x+=y;
    if(x<0) x+=mod;
    while(x>=mod) x-=mod;
}
int pos(char c) {
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='T') return 2;
    else return 3;
}
void insert(string s ,int len) {
    int now=0;
    for(int i=0;i<len;i++) {
        if(ch[now][pos(s[i])]==0) ch[now][pos(s[i])]=++tot;
        now=ch[now][pos(s[i])];
    }
    val[now]=len;
}
void build() {
    queue<int> q;
    for(int i=0; i<=3; i++) if(ch[0][i]) fail[ch[0][i]]=0,q.push(ch[0][i]);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int i=0; i<=3; i++) {
            int &v=ch[u][i];
            if(v==0) v=ch[fail[u]][i];
            else{
                fail[v]=ch[fail[u]][i]; q.push(v); val[v]=max(val[v],val[fail[v]]);
            }
        }
    }
}
main() {
    cin>>n>>m; int len;
    for(int i=1; i<=m; i++){
        cin>>ss;len=ss.size();
        mx=max(mx,len); insert(ss,len);
    }
    build();
    f[0][0][0]=1;
    for(int i=0; i<n; i++)
        for(int j=0; j<=tot; j++)
            for(int k=0,v; k<=mx; k++)
                if(v=f[i][j][k]) {
                    for(int p=0; p<=3; p++) {
                        int now=ch[j][p];
                        if(val[now]>k) add(f[i+1][now][0],v);
                        else if(k<mx) add(f[i+1][now][k+1],v);
                    }
                }
    int ans=0;
    for(int i=0; i<=tot; i++) add(ans,f[n][i][0]);
    cout<<ans<<"\n";
    return 0;
}