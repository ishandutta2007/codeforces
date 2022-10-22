#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;

void go(int ln){
	for (int r = n; r > 0; r -= ln){
		int l = max(1, r - ln + 1);
		for (int i = l; i <= r; i++)
			cout << i << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	int ans = 1e9;
	for (int i = 1; i <= n; i++){
		int temp = i + (n + (i-1))/ i;
		ans = min(ans, temp);
	}

	for (int i = 1; i <= n; i++){
		int temp = i + (n + (i-1))/ i;
		if (ans == temp){
			go(i);
			return 0;
		}
	}
	return 0;
}