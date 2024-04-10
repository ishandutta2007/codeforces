#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int N = 1e5+5,INF=0x7fffffff;
int a,b,h,w,n,A[N];
typedef long long ll;

ll pw[N][35];

map<int,int> m;

bool good(ll h, ll w, map<int,int>::iterator it) {
	if(h >= a && w >= b)
		return true;
	if(it == m.end()) return false;
	int s = it->first, amt = it->second;
	++it;
	if(h >= a) return good(h,w*pw[s][amt],it);
	if(w >= b) return good(h*pw[s][amt],w,it);
	for(int i = 0; i <= amt; ++i) 
		if(good(h*pw[s][i],w*pw[s][amt-i],it))
			return true;
	return false;
}

int solve(int h, int w) {
	m.clear();
	if(h >= a && w >= b) return 0;
	for(int i = 0; i < n; ++i) {
		++m[A[i]];
		if(good(h,w,m.begin()))
			return i+1;
	}
	return INF;
}

int main() {
	ios::sync_with_stdio(0);
	for(int i = 0; i < N; ++i) {
		pw[i][0] = 1;
		for(int j = 1; j < 35; ++j)
			pw[i][j] = min(ll(N),pw[i][j-1]*i);
	}
	cin>>a>>b>>h>>w>>n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	sort(A,A+n);
	reverse(A,A+n);
	int m = min(solve(h,w),solve(w,h));
	if(m == INF) cout << "-1\n";
	else cout << m << "\n"; 
	return 0;
}