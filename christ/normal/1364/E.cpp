#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
int query (int i, int j) {
	printf ("? %d %d\n",i,j);
	fflush(stdout);
	int ret; scanf ("%d",&ret);
	assert(ret != -1);
	return ret;
 
}
mt19937 rng(58);
int rand (int a, int b) {
	return uniform_int_distribution<int>(a,b)(rng);
}
int N;
int get (int bits, const vector<int> &poss) {
	int n = (int)poss.size();
	assert(n <= (1 << bits));
	if (bits == 1) {
		int i = poss[0], j = poss[1];
		while (true) {
			int k;
			do {
			    k = rand(1,N);
			} while (k == i || k == j);
			int a = query(i,k), b = query(j,k);
			if (a < b) return i;
			if (b < a) return j;
		}
	} else if (bits == 2) {
		vector<vector<int>> at(n,vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				at[i][j] = at[j][i] = query(poss[i],poss[j]);
		int ret = -1, mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			set<int> st;
			st.insert(0);
			for (int j = 0; j < n; j++) if (j != i) {
				st.insert(at[i][j]);
			}
			if ((int)st.size() == n && *st.rbegin() < mn) {
				mn = *st.rbegin();
				ret = poss[i];
			}
		}
		assert(ret != -1);
		return ret;
	}
	int want = bits / 2; //get this many 0s
	int i,j,got;
	do { //GOOD
		do {
			i = rand(0,n-1);
			j = rand(0,n-1);
		} while (i == j);
		i = poss[i]; j = poss[j];
		got = __builtin_popcount(query(i,j));
	} while (bits - got < want);
	vector<int> q(n);
	int mn = INT_MAX;
	for (int k = 0; k < n; k++) {
		if (poss[k] != i) {
			q[k] = query(i,poss[k]);
			mn = min(mn,q[k]);
		}
	}
	vector<int> new_poss;
	for (int k = 0; k < n; k++) 
		if (poss[k] == i || q[k] == mn)
			new_poss.push_back(poss[k]);
	int pw = 0, temp = 1;
	while (temp < (int)new_poss.size()) {
		temp *= 2;
		pw++;
	}
	return get(pw,new_poss);
}
int main () {
	int n; scanf ("%d",&n); N=n;
	//basically assume n == 2^11
	int pw = 0;
	{
		int temp = 1;
		while (temp < n) {
			temp *= 2;
			pw++;
		}
	}
	vector<int> all(n);
	iota(all.begin(),all.end(),1);
	int id = get(pw,all);
	vector<int> ret(n+1);
	for (int i = 1; i <= n; i++) ret[i] = i == id ? 0 : query(id,i);
	printf ("!");
	for (int i = 1; i <= n; i++) {
		printf (" %d",ret[i]);
	}
	printf ("\n");
	return 0;
}
//take ~10 queries to find 5 0s
//take n queries to find 2^6 candidates
//recursively get down to 4 candidates, then run n^2