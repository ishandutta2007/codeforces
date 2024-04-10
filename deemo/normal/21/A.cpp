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

int main(){
	string s;
	getline(cin, s);
    int i = 0;
	for (; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'z')	continue;
		if (s[i] >= 'A' && s[i] <= 'Z')	continue;
		if (s[i] >= '0' && s[i] <= '9')	continue;
		if (s[i] == '_')	continue;
		if (s[i] == '@')	break;
		cout << "NO" << endl;
		return 0;
	}
	if (i == 0 || i > 16){
		cout << "NO" << endl;
		return 0;
	}
	i++;
	if (i >= s.size()){
		cout << "NO" << endl;
		return 0;
	}
	int c = i;
	bool fl = 0;
	
	string t = "";
	for (; i < s.size(); i++){
		if (t.size() > 16){
			cout << "NO" << endl;
			return 0;
		}
		if (s[i] >= 'a' && s[i] <= 'z')	{t += s[i]; continue;}
		if (s[i] >= 'A' && s[i] <= 'Z')	{t += s[i]; continue;}
		if (s[i] >= '0' && s[i] <= '9')	{t += s[i]; continue;}
		if (s[i] == '_')	{t += s[i]; continue;}
		if (s[i] == '.'){
			if (t.size() == 0){
				cout << "NO" << endl;
				return 0;
			}
			t = "";
			continue;
		}
		if (t.size() == 0){
			cout << "NO" << endl;
			return 0;
		}
		if (s[i] != '/'){
			cout << "NO" << endl;
			return 0;
		}
		fl = 1;
		break;
	}	
	if (t.size() == 0 || i - c > 32){
		cout << "NO" << endl;
		return 0;
	}

	i++;
	if (fl && i >= s.size()){
		cout << "NO" << endl;
		return 0;
	}
	c = i;
	for (; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'z')	continue;
		if (s[i] >= 'A' && s[i] <= 'Z')	continue;
		if (s[i] >= '0' && s[i] <= '9')	continue;
		if (s[i] == '_')	continue;
		cout << "NO" << endl;
		return 0;
	}
	if (i - c > 16){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}