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

int DaysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weekdays[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int Read() {
	string str;
	cin >> str;
	return find(weekdays, weekdays + 7, str) - weekdays;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a = Read();
	int b = Read();

	for(int i = 0; i < 12; ++i) {
		if((a + DaysOfMonth[i]) % 7 == b) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/