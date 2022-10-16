#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

priority_queue<int> a[100001];
int sm[100001];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		int s, r;
		cin >> s >> r;
		a[s].push(r);
	}
	int ans = 0, anss = 0;
	vector<int> idx(m);
	iota(begin(idx),end(idx),1);
	while(idx.size()) {
		for(int j=0;j<idx.size();j++) {
			int & i = idx[j];
			if(a[i].empty()){
				ans -= sm[i];
				sm[i] = -87;
				i = idx.back();
				idx.pop_back();
				--j;
			}
		}
		int tmp = 0;
		for(int j=0;j<idx.size();j++) {
			int & i = idx[j];
			int tmptmp = a[i].top();
			tmp += tmptmp;
			a[i].pop();
			if ((sm[i] += tmptmp) <= 0) {
				tmp -= sm[i], sm[i] = -1;
				i = idx.back();
				idx.pop_back();
				--j;
			}
			
		}
		if(tmp > 0)
			ans += tmp;
		anss = max(anss, ans);
	}
	cout << anss << endl;
}