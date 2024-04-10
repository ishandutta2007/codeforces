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
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	multiset<int> s;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		s.insert(t);
		s.insert(t+n);
	}
	vi v;
	for(int i=0;i<n;i++) {
		int l = n - a[i];
		int d = *s.lower_bound(l), dd;
		if(d < n) dd = n + d;
		else dd = d - n;
		s.erase(s.lower_bound(d)), s.erase(s.lower_bound(dd));
		v.PB((a[i]+d)%n);
	}
	for(int e:v)
		cout << e << " ";

}