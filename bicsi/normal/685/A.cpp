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

vector<int> Digits(int n) {
	vector<int> A;
	while(n) {
		A.push_back(n % 7);
		n /= 7;
	}
	reverse(A.begin(), A.end());
	if(A.empty()) A.push_back(0);
	return A;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	n--; m--;

	
	vector<int> DN = Digits(n);
	vector<int> DM = Digits(m);

	if(DN.size() + DM.size() > 7) {
		cout << 0 << '\n';
		return 0;
	}

	vector<int> Perm;
	for(int i = 0; i < 7; ++i)
		Perm.push_back(i);

	set<pair<vector<int>, vector<int>>> Set;

	//arr_dump(DN, DN.size());
	//arr_dump(DM, DM.size());

	do {
		auto Aux = Perm;
		vector<int> AM, AN;

		int bad = 0;

		bool lss = 0;
		for(int i = 0; i < DN.size(); ++i) {
			if(!lss && Aux.back() > DN[i])
				bad = 1;
			else {
				if(Aux.back() < DN[i])
					lss = 1;
				AN.push_back(Aux.back());
				Aux.pop_back();
			}
		}

		lss = 0;
		for(int i = 0; i < DM.size(); ++i) {
			if(!lss && Aux.back() > DM[i])
				bad = 1;
			else {
				if(Aux.back() < DM[i])
					lss = 1;
				AM.push_back(Aux.back());
				Aux.pop_back();
			}
		}

		if(!bad)
			Set.insert({AM, AN});
	} while(next_permutation(Perm.begin(), Perm.end()));
	

	cout << Set.size() << endl;	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/