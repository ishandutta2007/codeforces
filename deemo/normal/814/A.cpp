#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 200 + 10;

int n, k, a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < k; i++)	cin >> b[i];
	sort(b, b + k);
	reverse(b, b + k);
	
	int cur = 0;
	for (int i = 0; i < n; i++)
		if (!a[i]){
			a[i] = b[cur++];
			break;
		}
	
	for (int i = 0; i + 1 < n; i++)
		if (a[i+1] <= a[i]){
			cout << "Yes\n";
			return 0;
		}
	cout << "No\n";
	return 0;
}