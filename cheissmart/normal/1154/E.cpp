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

int pre[200005], nxt[200005], a[200005], t[200005];

void link(int a, int b) {
	if(a)
		nxt[a] = b;
	if(b)
		pre[b] = a;
}

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(i) 
			link(a[i-1], a[i]);
	}
	int team = 1;
	for(int i=n;i>=1;i--) {
		if(t[i]) continue;
		int r = i, l = i;
		t[i] = team;
		for(int j=0;j<k;j++) {
			r = nxt[r];
			l = pre[l];
			t[l] = t[r] = team;
		}
		link(pre[l], nxt[r]);
		team ^= 3;
		
	}
	for(int i=0;i<n;i++)
		cout << t[a[i]];
}