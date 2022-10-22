#include<bits/stdc++.h>

using namespace std;

int ln[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string nm[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(){
	string s, t;
	cin >> s >> t;
	
	for (int i = 0; i < 7; i++){
		bool fl = 0;
		int cur = i;
		for (int j = 0; j < 12; j++){
			if (nm[cur % 7] == t){
				if (fl){
					cout << "YES\n";
					return 0;
				}
			}
			if (nm[cur % 7] == s){
				fl = 1;
			}
			else	fl = 0;
			cur += ln[j];
		}
	}

	cout << "NO\n";
	return 0;
}