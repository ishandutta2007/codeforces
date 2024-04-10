#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3505, P = 1000000007;
int p, k, m, n, nn, ans, a[N], f[N][N][2][2];
char s[N], t[N];
bool work(){
	int mm=0;
	ll now=0;
	for(int i=0; i<m; ++i){
		now=now*10ll+s[i];
		if(mm || now>=p) t[mm++]=now/p, now%=p;
	}
	a[++n]=now;
	memcpy(s, t, m=mm);
	return mm;
}
void update(int &x, ll y){ x=(x+y)%P;}
int main() {
	scanf("%d%d%s", &p, &k, s), m=strlen(s);
	for(int i=0; i<m; ++i) s[i]-='0';
	while(work());
	reverse(a+1, a+n+1);
	f[1][0][0][0]=1;
	for(int i=1; i<=n; ++i) for(int j=0; j<i; ++j){
		ll k00=p*(p+1ll)/2%P, k01=p*(p-1ll)/2%P, k10=k01, k11=k00;
		update(f[i+1][j][0][1], f[i][j][0][1]*k00+f[i][j][1][1]*k10);
		update(f[i+1][j+1][1][1], f[i][j][0][1]*k01+f[i][j][1][1]*k11);
		if(a[i]){
			k00=(ll)a[i]*(a[i]+1)/2%P, k01=(ll)a[i]*(a[i]-1)/2%P;
			k10=(p+p-a[i]-1ll)*a[i]/2%P, k11=(p+p-a[i]+1ll)*a[i]/2%P;
			update(f[i+1][j][0][1], f[i][j][0][0]*k00+f[i][j][1][0]*k10);
			update(f[i+1][j+1][1][1], f[i][j][0][0]*k01+f[i][j][1][0]*k11);
		}
		update(f[i+1][j][0][0], f[i][j][0][0]*(a[i]+1ll)+(ll)f[i][j][1][0]*(p-a[i]-1ll));
		update(f[i+1][j+1][1][0], (ll)f[i][j][0][0]*a[i]+(ll)f[i][j][1][0]*(p-a[i]));
	}
	for(int i=k; i<=n; ++i) update(ans, f[n+1][i][0][0]+f[n+1][i][0][1]);
	printf("%d\n", ans);
	return 0;
}