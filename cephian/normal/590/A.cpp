#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 5e5+5;
int a[N];
int start[N];

int main() {	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	bool c = 0;
	int lg = 1, cur = 1;
	start[0] = 0;
	for(int i = 1; i < n; ++i) {
		if(a[i] != a[i-1]) {
			start[i] = start[i-1];
		} else start[i] = i;
		lg = max(lg,i-start[i]+1);
	}
	cout << (lg+1)/2-1 << "\n";
	for(int i = n-1; i >= 0; ) {
		int d = i-start[i];
		for(int j = start[i]; j <= i; ++j) {
			if(d%2 == 0)
				a[j] = a[i];
			else if(j-start[i] < (d+1)/2)
				a[j] = a[start[i]];
			else
				a[j] = a[i];

		}
		i = start[i]-1;
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}