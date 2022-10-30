#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, P = 1000000007;
int n, ans, top, f[N], l[N], stk[N], pos[N], r[N][2];
char s[N];
int main() {
	scanf("%s", s+1), n=strlen(s+1);
	for(int i=n; i; --i) r[i][1]=s[i+1]=='1'?i+1:r[i+1][1];
	for(int i=n; i; --i) if(s[i]=='0'){
		int j=i;
		while(j>0 && s[j-1]=='0') --j;
		int len=i-j+1;
		while(top && stk[top]<=len) --top;
		if(top && j>1) r[i][0]=pos[top]+len;
		for(int k=j; k<i; ++k) r[k][0]=k+1;
		for(int k=j; k<=i; ++k) l[k]=k-j+1;
		stk[++top]=len, pos[top]=j;
		i=j;
	}
	else r[i][0]=pos[top];
	f[1]=1;
	if(s[1]=='0') f[r[1][1]]=1;
	for(int i=0; i<=n; ++i){
		if(i && (s[i]=='1' || !r[i][1] || (l[i]!=i && l[i]<=l[n]))) (ans+=f[i])%=P;
		if(r[i][0]) (f[r[i][0]]+=f[i])%=P;
		if(r[i][1]) (f[r[i][1]]+=f[i])%=P;
	}
	// printf(">> %d %d %d %d %d\n", f[1], f[2], f[3], f[4], f[5]);
	printf("%d\n", ans);
	return 0;
}