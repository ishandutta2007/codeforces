#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >>n;
	if(n % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++) {
		if(i % 2 == 0) {
			a[i] = i*2+1;
		} else {
			a[i] = i*2+2;
		}
	}
	for(int i=n;i<2*n;i++) {
		if(a[i-n]&1) a[i] = a[i-n]+1;
		else a[i] = a[i-n]-1;
	}
	for(int i=0;i<2*n;i++)
		cout << a[i] << " ";
}