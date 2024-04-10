#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

string s[100005];

int failure[1000005];

void build_failure(string &t) {
	for(int i=1, j=failure[0]=-1;i<t.size();i++) {
		while(j>=0 && t[j+1] != t[i])
			j = failure[j];
		if(t[j+1] == t[i])
			j++;
		failure[i] = j;
	}
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> s[i];
	string t = s[0];
	for(int i=1;i<n;i++) {
		string r;
		if(s[i].size() <= t.size()) 
			r = s[i] + "#" + t.substr(t.size()-s[i].size());
		else
			r = s[i].substr(0, t.size()) + "#" + t;
		build_failure(r);
		int m = failure[r.size()-1]+1;
		if(m < s[i].size()) t += s[i].substr(m);
	}
	cout << t << endl;
}