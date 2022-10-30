#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<string,int> m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		string k;
		cin >> s >> k;
		while(k.size()<20) k = "0"+k;
		for(int i = 0; i < k.size(); ++i) {
			if((k[i]-'0')&1) k[i] = 1;
			else k[i] = 0;
		}
		if(s == "+") ++m[k];
		else if(s=="-") --m[k];
		else cout << m[k] << "\n";
	}


	return 0;
}