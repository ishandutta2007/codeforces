#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

bool ok(string s){
	if (s.size() == 0)	return	false;
	if (s == "0")	return	true;
	if (s[0] == '-' || s[0] == '0')	return	false;
	for (int i = 0; i < s.size(); i++)
		if (s[i] < '0' || s[i] > '9')	return	false;
	return	true;
}

int main(){
	read_fast;
	string s;	cin >> s;
	vector<string>	vec, sec;
	for (int i = 0; i < s.size();){
		string temp = "";
		int j = i;
		while (j < s.size() && s[j] != ',' && s[j] != ';')	temp += s[j++];
		if (ok(temp))	vec.push_back(temp);
		else	sec.push_back(temp);
		i = j + 1;
	}
	if (s.back() == ',' || s.back() == ';')	sec.push_back("");
	if (vec.size() == 0)	cout << "-" << endl;
	else{
		cout << '"';
		for (int i = 0; i < vec.size(); i++){
			cout << vec[i];
			if (i != vec.size() - 1)
				cout << ',';
		}
		cout << '"' << endl;
	}
	if (sec.size() == 0)	cout << "-" << endl;
	else{
		cout << '"';
		for (int i = 0; i < sec.size(); i++){
			cout << sec[i];
			if (i != sec.size() - 1)
				cout << ',';
		}
		cout << '"' << endl;
	}
    return 0;
}