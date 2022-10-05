/*
nsK
tn
i,j(i<j)t[i..j] > s[i..j]
K
n,K<=2000

t[i]<s[i], 0
t[i]>s[i], n-i
t[i]=s[i], k(k>i)t[i]!=s[i]
	t[k]<s[k], 0
	t[k]>s[k], n-k
	
t[i]>s[i](pre+1)*(n-i)
pres[1..i-1], t[1..i-1]

f[i][sum]s[i]!=t[i]isum
(s[i]=t[i]pre)
pre
f[i][k]
O(k*(n+klogk))

t[i]<s[i]
f[i][sum]+=f[i-1-pre][sum]*(s[i]-'a')
t[i]<s[i]
f[i][sum]+=f[i-1-pre][sum-(pre+1)*(n-i)]*('z'-s[i])
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2017;
const int MOD = 1000000007;
int f[maxn][maxn], g[maxn][maxn], n, K, ans;
char s[maxn];

int main(){
	scanf("%d%d", &n, &K);
	scanf("%s", s+1);
	f[0][0] = 1; g[0][0] = 1;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=K; j++){
			f[i][j] = 1LL * g[i-1][j] * (s[i]-'a') % MOD;
			for (int pre=0; pre<=i-1&&(pre+1)*(n-i+1)<=j; pre++)
				f[i][j] = (f[i][j] + 1LL*f[i-1-pre][j-(pre+1)*(n-i+1)]*('z'-s[i])) % MOD;
			g[i][j] = (g[i-1][j] + f[i][j]) % MOD;
		}		
	for (int i=0; i<=n; i++) ans = (ans + f[i][K]) % MOD;
	printf("%d\n", ans);
	return 0;
}