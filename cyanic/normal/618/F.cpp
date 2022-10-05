/*
AB
1~n
Aka
Bkb

Ka,Kb,
n<=1,000,000
*/
#include<bits/stdc++.h>
using namespace std;

inline int read(){
	char ch = getchar(); int x = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return x;
}

const int maxn = 1000009;
long long SA[maxn], SB[maxn];
int p[maxn], q[maxn], n, k = 0, flag;

void print(int a, int b, int c, int d){
	if (flag) { swap(a, c); swap(b, d); }
	printf("%d\n", b-a+1);
	for (int i=a; i<=b; i++) printf("%d ", i); puts("");
	printf("%d\n", d-c+1);
	for (int i=c; i<=d; i++) printf("%d ", i); puts("");
}

int main(){
	n = read();
	for (int i=1; i<=n; i++) SA[i] = SA[i-1] + read();
	for (int i=1; i<=n; i++) SB[i] = SB[i-1] + read();
	if (SA[n] > SB[n]){
		flag = 1; for (int i=1; i<=n; i++) swap(SA[i], SB[i]);
	}
	memset(p, -1, sizeof p);
	memset(q, -1, sizeof q);
	for (int i=0; i<=n; i++){
		while (k+1 <= n && SB[k+1] <= SA[i]) k++;
		if (p[SA[i]-SB[k]] != -1){
			print(p[SA[i]-SB[k]]+1, i, q[SA[i]-SB[k]]+1, k);
			return 0;
		}
		p[SA[i]-SB[k]] = i;
		q[SA[i]-SB[k]] = k;
	}
	return 0;
}