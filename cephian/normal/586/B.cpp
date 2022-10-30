#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 50;
int A[N]={},B[N]={},C[N];

vector<int> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i)
		cin >> A[i];
	for(int i = 0; i < n-1; ++i) {
		cin >> B[i];
	}
	for(int i = 0; i < n; ++i)
		cin >> C[i];
	for(int i = 1; i < n; ++i) {
		A[i] += A[i-1];
		B[n-i-1] += B[n-i];
	}
	for(int i = 0; i < n; ++i) {
		v.push_back(A[i] + C[i] + B[i]);
	}
	sort(v.begin(),v.end());
	cout << v[0] + v[1] << "\n";
	
}