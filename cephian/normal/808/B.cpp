#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

long double sm = 0;
long double A[200005]={};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];
		A[i] += A[i-1];
	}
	long double sm = 0;
	for(int i = k; i <= n; ++i)
		sm += A[i]-A[i-k];
	cout << setprecision(14) << fixed << sm/(n-k+1) << "\n";
}