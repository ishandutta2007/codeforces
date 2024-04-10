#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

string s1, s2;

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> s2;
	set<string> se;
	for (int i = 0; i < s1.size(); i++) for (int j = 0; j < s2.size(); j++){
		string now;
		for (int s = 0; s <= i; s++) now += s1[s];
		for (int s = 0; s <= j; s++) now += s2[s];
		se.insert(now);
	}

	cout << *se.begin();
}