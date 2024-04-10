#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 505, K = 180, M = 1<<16, P = 1000000007;
int n, cnt, ans, root, q[16], aa[M], bb[M], b[M], a[2][4][M], f[K][M];
char s[M];
void solve_or(int *f, int *a, int *b){
	memcpy(aa, a, M<<2), memcpy(bb, b, M<<2);
	for(int i=0; i<16; ++i) for(int j=0; j<M; ++j) if(j>>i&1)
		(aa[j]+=aa[j-(1<<i)])%=P, (bb[j]+=bb[j-(1<<i)])%=P;
	for(int i=0; i<M; ++i) aa[i]=(ll)aa[i]*bb[i]%P;
	for(int i=0; i<16; ++i) for(int j=0; j<M; ++j) if(j>>i&1)
		(aa[j]+=P-aa[j-(1<<i)])%=P;
	for(int i=0; i<M; ++i) (f[i]+=aa[i])%=P;
}
void solve_and(int *f, int *a, int *b){
	memcpy(aa, a, M<<2), memcpy(bb, b, M<<2);
	for(int i=0; i<16; ++i) for(int j=0; j<M; ++j) if(j>>i&1)
		(aa[j-(1<<i)]+=aa[j])%=P, (bb[j-(1<<i)]+=bb[j])%=P;
	for(int i=0; i<M; ++i) aa[i]=(ll)aa[i]*bb[i]%P;
	for(int i=0; i<16; ++i) for(int j=0; j<M; ++j) if(j>>i&1)
		(aa[j-(1<<i)]+=P-aa[j])%=P;
	for(int i=0; i<M; ++i) (f[i]+=aa[i])%=P;
}
int work(int l, int r){
	int x=++cnt;
	if(l==r){
		if(s[l]=='?') memcpy(f[x], b, M<<2);
		else memcpy(f[x], a[!!islower(s[l])][s[l]-(isupper(s[l])?'A':'a')], M<<2);
		return x;
	}
	int mid=0;
	for(int i=l, now=0; i<r; ++i){
		if(s[i]=='(') ++now; else if(s[i]==')') --now;
		if(!now){ mid=i+1; break;}
	}
	int u=work(l+1, mid-2), v=work(mid+2, r-1);
	if(s[mid]!='&') solve_or(f[x], f[u], f[v]);
	if(s[mid]!='|') solve_and(f[x], f[u], f[v]);
	return x;
}
int main() {
	scanf("%s%d", s, &n);
	for(int x=0; x<4; ++x){
		for(int i=0; i<M; ++i){
			a[0][x][i]=a[1][x][i]=1;
			for(int j=0; j<16; ++j)
				a[0][x][i]&=((i>>j&1)==(j>>x&1)),
				a[1][x][i]&=((i>>j&1)!=(j>>x&1));
			b[i]+=a[0][x][i]+a[1][x][i];
		}
	}
	root=work(0, strlen(s)-1);
	memset(q, -1, sizeof q);
	while(n--){
		int x=0;
		for(int i=0, t; i<4; ++i) scanf("%d", &t), x|=t<<i;
		scanf("%d", q+x);
	}
	for(int i=0; i<M; ++i){
		for(int j=0; j<16; ++j) if(~q[j] && (i>>j&1)!=q[j]) goto skip;
		(ans+=f[root][i])%=P;
		skip:;
	}
	printf("%d\n", ans);
	return 0;
}