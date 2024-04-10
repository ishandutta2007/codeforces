#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e6 + 10;

int n,a,b,x,k;
int aa[MAXN]; 
int tmp1,tmp2;
int s1,s2,s3,at[4];
bool flag = false;
int v[5][MAXN];
string s;

template <typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = (a << 3) + (a << 1) + (c ^ 48); c = getchar();}
	a *= f;
}

int main () {
	read(n);
	cin >> s;
	for(register int i = 1;i <= n; ++i)
		aa[i] = s[i - 1] - '0';
	cin >> s;
	for(register int i = 1;i <= n; ++i) {
		tmp1 = aa[i];
		tmp2 = s[i - 1] - '0';
		v[tmp1 * 2 + tmp2][++at[tmp1 * 2 + tmp2]] = i;
		if(tmp1 == 0 && tmp2 == 1) s1++;
		if(tmp1 == 1 && tmp2 == 0) s2++;
		if(tmp1 == 1 && tmp2 == 1) s3++;
	}
	for(x = max(0,(s1 + s3 - n / 2)),k;x <= min(s3,(n / 2 - s2)); ++x) {
		k = s3 - 2 * x;
		int l = max(0,k),r = min(s2,s1 + k);
		if(l > r) continue;
		a = l,b = a - k;
		if(0 <= a && a <= s2 && 0 <= b && b <= s1) {flag = true; break;}
	}
	if(!flag) {puts("-1"); return 0;}
	for(register int i = 1;i <= s1 - b; ++i) printf("%d ",v[1][at[1]--]);
	for(register int i = 1;i <= x; ++i) printf("%d ",v[3][at[3]--]);
	for(register int i = 1;i <= a; ++i) printf("%d ",v[2][at[2]--]);
	for(register int i = 1;i <= n / 2 - (s1 - b + x + a); ++i) printf("%d ",v[0][at[0]--]);
	//for(register int i = 1;i <= s2 - a; ++i) printf("%d ",v[2][at[2]--]);
	//for(register int i = 1;i <= s3 - x; ++i) printf("%d ",v[3][at[3]--]);
	//for(register int i = 1;i <= b; ++i) printf("%d ",v[1][at[1]--]);
	//for(register int i = 1;i <= n / 2 - (s2 - a + s3 - x + b); ++i) printf("%d ",v[0][at[0]--]);
	puts("");
	return 0;
}