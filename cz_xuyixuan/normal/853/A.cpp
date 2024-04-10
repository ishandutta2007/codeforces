#include<bits/stdc++.h>
using namespace std;
#define MAXN	300005
struct info {int value, pos; };
bool operator < (info x, info y) {
	return x.value < y.value;
}
int n, k, value[MAXN], a[MAXN];
long long sum, ans;
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	static priority_queue <info> Heap;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	for (int i = 1; i <= k; i++) {
		ans += sum;
		sum += value[i];
		Heap.push((info) {value[i], i});
	}
	for (int i = k + 1; i <= k + n; i++) {
		ans += sum;
		if (i <= n) {
			sum += value[i];
			Heap.push((info) {value[i], i});
		}
		info tmp = Heap.top();
		sum -= tmp.value;
		Heap.pop();
		a[tmp.pos] = i;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}