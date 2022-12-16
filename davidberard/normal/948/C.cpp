#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int bs(vector<ll>& v, int start, int N, ll goal) {
	int l = start;
	int r = N;
	goal++;
	while(l<r) {
		int m = (l+r)/2;
		if(v[m] < goal)
			l = m+1;
		else if(v[m] >= goal)
			r = m-1;
	}
	if(v[l] >= goal)
		return l-1;
	return l;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	vector<ll> delta(N, 0), extra(N, 0);
	vector<ll> pfx(N+1, 0);
	vector<ll> T(N), V(N);
	for(int i=0;i<N;++i) cin >> V[i];
	for(int i=0;i<N;++i) cin >> T[i];
	for(int i=0;i<N;++i) {
		pfx[i+1] = pfx[i]+T[i];
	}
	for(int i=0;i<N;++i) {
		int stop = bs(pfx, i, N, pfx[i]+V[i]);
		delta[i]++;
		if(stop < N) {
			delta[stop]--;
			extra[stop] += V[i] - (pfx[stop]-pfx[i]);
		}
	}
	ll cnt = 0;
	for(int i=0;i<N;++i) {
		cnt += delta[i];
		cout << T[i]*cnt + extra[i] << " ";
	}
	cout << endl;

	return 0;
}