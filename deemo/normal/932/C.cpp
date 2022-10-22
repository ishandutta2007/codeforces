#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int ta = -1, tb = -1;
	for (int i = 0; i <= n/a; i++) {
		int rem = n-i*a;
		if (rem % b == 0){
			ta = i;
			tb = rem/b;
			break;
		}
	}
	if (ta == -1)
		cout << "-1\n";
	else {
		int cur = 1;
		while (ta--){
			for (int i = 0; i < a; i++)
				cout << (i == a-1? cur: cur + i + 1) << " ";
			cur += a;
		}
		while (tb--){
			for (int i = 0; i < b; i++)
				cout << (i == b-1? cur: cur + i + 1) << " ";
			cur += b;
		}
		cout << "\n";
	}
	return 0;
}