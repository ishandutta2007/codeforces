#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[100007];

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int mi = 2e9;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mi = min(mi, a[i]);
	}
	int last = -1;
	int ans = 1e9;
	for (int i = 0; i < n; i++){
		if (a[i] == mi){
			if (last != -1){
				ans = min(ans, i - last);
			}
			last = i;
		}
	}
	cout << ans;
}