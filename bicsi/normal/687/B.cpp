/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

int Large[2000000];
int Fact[2000000], Fact2[2000000];
bool Seen[2000000];

void Factorize(int val, int Fact[]) {
	while(val > 1) {
		int p = Large[val], e = 0;
		while(val % p == 0) {
			++e;
			val /= p;
		}
		Fact[p] = max(Fact[p], e);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for(int i = 2; i <= 1000000; ++i) {
		if(Large[i] == 0) {
			for(int j = i; j <= 1000000; j += i)
				Large[j] = i;
		}
	}

	//for(int i = 1; i <= 20; ++i)
	//	cerr << Large[i] << " ";

	int m;
	cin >> m;
	Factorize(m, Fact);

	int gc = 0;
	for(int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		if(Seen[v]) continue;

		Seen[v] = 1;
		Factorize(v, Fact2);
		gc = __gcd(gc, v);
	}


	for(int i = 2; i <= 1000000; ++i)
		if(Fact[i] > Fact2[i]) {
			cout << "No\n";
			return 0;
		}

	cout << "Yes\n";
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/