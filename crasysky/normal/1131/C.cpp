#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define mp make_pair
#define fi first
#define se second
#define maxn 100005
using namespace std;
int a[maxn], n, q[maxn];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	n = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	int l = n, r = n;
	q[l] = a[1];
	for (int i = 2; i <= n; ++ i){
		if (q[l] < q[r])
			q[-- l] = a[i];
		else
			q[++ r] = a[i];
	}
	for (int i = l; i <= r; ++ i)
		cout << q[i] << " ";
	cout << endl;
}