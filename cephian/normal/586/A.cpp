#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int A[105]={};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> A[i];
	int a=0;
	for(int i = 1; i <= n; ++i)
		a += A[i]==1 || (A[i-1]==1 && A[i+1]==1);
	cout << a << "\n";
}