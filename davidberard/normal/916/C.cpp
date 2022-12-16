#include <bits/stdc++.h>
#define nl "\n"

// as
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<bool> ps;
vector<int> lowprimes;

void primes() {
	ps = vector<bool>(110000, false);

	for(int i=2;i<110000;++i) {
		if(ps[i] == false) {
			for(ll j=(ll)i*i;j<110000;j+=i)
				ps[j] = true;
			lowprimes.push_back(i);
		}
	}
}

/*
bool isPrime(int i) {
	if(i < 2) return false;
	if(i < 110000)
		return !ps[i];
	bool prob = false;
	for( int ii : lowprimes ) {
		if(i%ii) {
			prob = true;
			break;
		}
	}
	return !prob;
}
*/

int nextPrime(int i) {
	vector<int>::iterator res = lower_bound(lowprimes.begin(), lowprimes.end(), i);
	int vv = *res;
	return vv;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	primes();

	int N, M;
	cin >> N >> M;
	
	vector<vector<pii> > edges(N);

	int cnt = 0;
	edges[0].push_back(pii(N-1, 2));
	edges[N-1].push_back(pii(0, 2));
	for(int i=1;i<N-2;++i) {
		edges[0].push_back(pii(i, 1));
		edges[i].push_back(pii(0, 1));
	}
	int aa = nextPrime(N);
	int mmm = aa-(N-1) + 5;
	edges[0].push_back(pii(N-2, aa-(N-1)));
	edges[N-2].push_back(pii(0, aa-(N-1)));
	cnt = N-1;

	for(int i=1;i<N && cnt < M;++i) {
		vector<bool> used(N, false);
		for( pii ii : edges[i] )
			used[ii.first] = true;
		for(int j=1;j<N && cnt < M;++j) {
			if(j <= i || used[j]) continue;
			used[j] = true;
			edges[i].push_back(pii(j, mmm));
			edges[j].push_back(pii(i, mmm));
			++cnt;
		}
	}

	cout << 2 << " " << aa << nl;
	for(int i=0;i<N;++i) {
		for(pii ii : edges[i]) {
			if(ii.first <= i) continue;
			cout << i+1 << " " << ii.first+1 << " " << ii.second << nl;
		}
	}
	

	return 0;
}