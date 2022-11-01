#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 32;
int T, n, P, f[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &P);
		int m, ans=0;
		for(m=31; !(n>>m&1); --m);
		for(int i=0; i<=m; ++i){
			f[i]=0;
			for(int j=0; j<i; ++j) (f[i]+=f[j])%=P;
			f[i]=(f[i]+1ll)*(i<m?1<<i:n-(1<<i)+1)%P;
			(ans+=f[i])%=P;
		}
		printf("%d\n", ans);
	}
	return 0;
}