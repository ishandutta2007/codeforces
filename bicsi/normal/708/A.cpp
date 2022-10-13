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

int A[kMaxN], B[kMaxN];

char prev(char x) {
	return char(x - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int start = -1;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] != 'a') {
			start = i;
			break;
		}
	}

	if(start == -1) {
		str.back() = 'z';
		cout << str << endl;
		return 0;
	}

	for(int i = start; i < str.size() && str[i] != 'a'; ++i) {
		str[i] = prev(str[i]);
	}
	cout << str << endl;

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/