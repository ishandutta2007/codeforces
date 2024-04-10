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

const int N = 55;
ll opt[N]={},a[N]={};
ll lft[N] = {};

int main() {
	fio;	
	 int n;
	 cin >> n;
	 for(int i = 0; i < n; ++i) {
	 	cin >> a[i];
	 }
	 for(int i = n-1; i >= 0; --i)
	 	lft[i] = lft[i+1] + a[i];
	 for(int i = n-1; i >= 0; --i) {
	 	for(int j = i; j < n; ++j) {
	 		opt[i] = max(opt[i],a[j] + (lft[j+1]-opt[j+1]));
	 	}
	 }
	cout << lft[0]-opt[0] << " " << opt[0] << "\n";
}