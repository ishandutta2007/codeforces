#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	vi v;
	v.PB(a[0]);
	for(int i=1;i<n;i++) {
		if(a[i] > v.back())
			v.PB(a[i]);
		else 
			*lower_bound(v.begin(), v.end(), a[i]) = a[i]; 
	}
	cout << v.size() << endl;
	
}