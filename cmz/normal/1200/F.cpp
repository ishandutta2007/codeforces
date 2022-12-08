#include <bits/stdc++.h>
using namespace std;
const int mod = 2520;
const int maxm=1020;
const int maxn=2550;
int n,inq[maxn][maxn], ans[maxn][maxn];
int w[maxn];
int dep[maxn][maxn];
int son[maxn][12], len[maxn];
int sta[maxm*maxn];
int cnt[maxn];
inline int dfs(int x, int y) {
    inq[x][y]=1;
    if(ans[x][y]!=0) return ans[x][y];
    
    sta[dep[x][y]] = x;
    int yy=y%len[x];
    
    if(inq[son[x][yy]][(y + w[son[x][yy]]) % mod]) {
        if(ans[son[x][yy]][(y + w[son[x][yy]]) % mod]) return ans[x][y] = ans[son[x][yy]][(y + w[son[x][yy]]) % mod];
        int l = dep[son[x][yy]][(y + w[son[x][yy]]) % mod], r = dep[x][y];
        for(int i = l; i <= r; i++) cnt[sta[i]] = 0;
        for(int i = l; i <= r; i++) if(cnt[sta[i]] == 0) cnt[sta[i]] = 1, ans[x][y]++;
        return ans[x][y];
    }
    
    dep[son[x][yy]][(y + w[son[x][yy]]) % mod] = dep[x][y] + 1;
    
    int nn=dfs(son[x][yy], (y + w[son[x][yy]]) % mod);
    
    ans[x][y] =nn;
    return nn;
    
}
inline int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0'||ch>'9'){
		if (ch=='-') flag=1;
		ch=getchar();
	} 
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	if (flag==1) return -x; else return x;
	
}
int main() {
	//freopen(".in","r",stdin);
    n=read();
    for(int i = 1; i <= n; i++) w[i]=(read()%mod+mod)%mod;
    
    for(int i = 1; i <= n; i++) {
        len[i]=read();
        for(int j = 0; j < len[i]; j++)son[i][j]=read();
    }
    int q;
    q=read();
    int x,c;
    while(q--) {
        x=read();
        c = (read() % mod + mod) % mod;
        printf("%d\n",dfs(x, (c + w[x]) % mod));
    }
int kkkk;
    return 0;
}