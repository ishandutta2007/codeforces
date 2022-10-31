#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<string,string> pss;

set<pair<string,string> > m;
string home;

int main() {
	int n;
	cin >> n;
	cin >> home;
	for(int i = 0; i < n; ++i) {
		string s,a,b;
		cin >> s;
		a = s.substr(0,3);
		b = s.substr(5,3);
		if(b < a) swap(a,b);
		pss p(a,b);
		if(m.count(p))
			m.erase(p);
		else
			m.insert(p);
	}
	if(m.size()) cout << "contest\n";
	else cout << "home\n";



	return 0;
}