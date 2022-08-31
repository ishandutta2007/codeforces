#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

using namespace std;

string a,b;

string smallest(string s) {
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr(s.length()/2, s.length()/2));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}

int main() {
    cin >> a >> b;
    
	if (smallest(a) == smallest(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
}