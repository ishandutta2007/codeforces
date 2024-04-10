#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6+50;
int t,n,m,k,h[N],now; char s[N];
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		bool flag = 1;
		for (int i = 1; i <= n; i++)scanf("%d", &h[i]);
		now = m;
		for (int i = 1; i < n; i++) {
			if (h[i + 1] - k <= h[i]) {
				now += min(h[i], h[i] + k - h[i + 1]);
			}
			else if (h[i + 1]-k <= h[i] + now)now -= (h[i + 1] - (h[i] + k));
			else { flag = 0; break;}
		}
		puts(flag ? "YES" : "NO");
	}
}