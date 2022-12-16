#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> offst;
int N;

int& offset(int index) {
	return offst[(unsigned int) index+N];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	vector<int> val(N);
	string s;
	cin >> s;
	for(int i=0;i<N;++i)
		val[i] = s.at(i)-'0';
	vector<int> prefix(N);
	offst = vector<int>(2*N+1, -1);
	
	offset(0) = 0;
	int amt = 0;
	int surpl;
	for(int i=0;i<N;++i) {
		amt += val[i];
		prefix[i] = amt;
		surpl = 2*amt-(i+1);
		if(offset(surpl) == -1)
			offset(surpl) = i+1;
	}
	
	int best = 0;
	int prfx, l;
	for(int i=N-1;i>=0;--i) {
		prfx = prefix[i];
		l = i+1;
		surpl = 2*prfx-l;
		if(offset(surpl) == -1) continue;
		best = max(l-offset(surpl), best);
	}
	
	cout << best << endl;


	return 0;
}