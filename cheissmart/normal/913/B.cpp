#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi ch[1024];
int isl[1024];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=2;i<=n;i++) {
		int t;
		cin >> t; 
		ch[t].PB(i);
	}
	for(int i=1;i<=n;i++)
		isl[i] = ch[i].size() == 0;
	for(int i=1;i<=n;i++) {
		if(isl[i]) continue;
		int ct = 0;
		for(int v:ch[i])
			ct += isl[v];
		if(ct < 3) {
			cout << "No" << endl;
			return 0;
		}
	} 
	cout << "Yes" << endl;
}