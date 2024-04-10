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

const int kMaxN = 500000;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;
	cin >> n >> str;

	deque<char> d;
	bool f = str.size() % 2;
	for(auto c : str) {
		if(!f) d.push_front(c);
		else d.push_back(c);
		f = !f;
	}

	for(auto c : d) cout << c;
	cout << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/