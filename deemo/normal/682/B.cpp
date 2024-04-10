#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	int t = n - 1;
	
	for (int i = 1; i <= n; i++){
		if (a[t] >= i){
			t--;
			continue;
		}
		t--;
		if (t < 0){
			cout << i << endl;
			return 0;
		}
		i--;
	}
	cout << n + 1 << endl;
	return 0;
}