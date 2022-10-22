#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 5;

int n, k, a[MAXN];
int mark[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int c = 0;
	for (int i = 0; i < n; i++) cin >> a[i], c += !(mark[a[i]]++);
	if (c < k)
		cout << "NO\n";
	else{
		cout << "YES\n";
		for (int i = 0; i < n && k; i++)
			if (mark[a[i]]){
				cout << i+1 << " ";
				mark[a[i]] = 0;
				k--;
			}
		cout << "\n";
	}
	return 0;
}