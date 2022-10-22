#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 2;

int n, a[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 1){
				bool found = 0;
				for (int c = 0; c < n; c++)
					for (int b = 0; b < n; b++)
						found |= a[i][c] + a[b][j] == a[i][j];

				if (!found){
					cout << "No\n";
					return 0;
				}
			}
	cout << "Yes\n";
	return 0;
}