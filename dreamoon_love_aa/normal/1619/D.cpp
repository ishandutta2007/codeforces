//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int MAX = 1 << 20, MOD = 1e9 + 7;
int tot[MAX];
 
void solve(){
	int m, n;
	cin >> m >> n;
	vector<vi> a(m, vi(n, 0));
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cin >> a[i][j]; 
		}
	}
	vector<vi> temp(m, vi(n + 1, 0));
	int l = 1, r = 1e9+5;
	while(l < r){
		int mid = (r - l) / 2 + l;
		int cnt = m;
		for(int i = 0;i < n;i++)
			tot[i] = 0; 
		for(int i = 0;i < m;i++){
			temp[i][0] = 0;
			for(int j = 0;j < n;j++){
				temp[i][j + 1] = 0;
				if(a[i][j] >= mid){
					temp[i][j + 1] = 1;
					temp[i][0]++;
					tot[j]++;
				}
			}
		}
		int flag = 0;
		for(int i = 0;i < n;i++){
			if(!tot[i]){
				flag = 1;
				break;
			}
		}
		if(flag){
			r = mid;
			continue;
		}
		sort(temp.begin(), temp.end());
		for(int i = 0;i < m;i++){
			int f = 1;
			for(int j = 0;j < n;j++){
				if(tot[j] <= 1 && temp[i][j + 1]){
					f = 0;
					break;
				}
			}
			if(!f)
				continue;
			cnt--;
			for(int j = 0;j < n;j++)
				tot[j] -= temp[i][j + 1];
		}
		if(cnt <= n - 1)
			l = mid + 1;
		else
			r = mid;
	}
	cout << l - 1 << '\n';
}
 
int main(){
	IOS
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}