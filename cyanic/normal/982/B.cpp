#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 200005;
struct node1 { 
	int w, p;
	bool operator < (const node1 &x) const {
		return w > x.w;
	}
} tmp1;
priority_queue<node1> Q1;
struct node2 {
	int w, p;
	bool operator < (const node2 &x) const {
		return w < x.w;
	}
} tmp2;
priority_queue<node2> Q2;
int n, w;
char s[maxn*2];

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d", &w);
		Q1.push((node1){w, i});
	}
	scanf("%s", s + 1);
	rep (i, 1, 2 * n) 
		if (s[i] == '0') {
			tmp1 = Q1.top(); Q1.pop();
			printf("%d ", tmp1.p);
			Q2.push((node2){tmp1.w, tmp1.p});
		}
		else {
			tmp2 = Q2.top(); Q2.pop();
			printf("%d ", tmp2.p);
		}
	
	return 0;
}