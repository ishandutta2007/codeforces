#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int cnt[26];

signed main()
{
	IO_OP;
	
	string s;
	cin >> s;
	for(char c:s) cnt[c-'a']++;
	if(s.size()&1) {
		vi v;
		for(int i=0;i<26;i++) if(cnt[i]&1) v.PB(i);
		int m = v[v.size()/2];
		for(int i=0;i<v.size();i++) {
			if(i == v.size()/2) continue;
			if(i < v.size()/2) cnt[v[i]]++;
			else cnt[v[i]]--;
		}
		string l, r;
		for(int i=0;i<26;i++)
			for(int j=0;j<cnt[i]/2;j++)
				l.PB('a'+i);
		r = l;
		reverse(ALL(r));
		cout << l << (char)(m+'a') << r << endl;
	} else {
		vi v;
		for(int i=0;i<26;i++) if(cnt[i]&1) v.PB(i);
		for(int i=0;i<v.size();i++)
			if(i < v.size()/2) cnt[v[i]]++;
			else cnt[v[i]]--;
		string l, r;
		for(int i=0;i<26;i++)
			for(int j=0;j<cnt[i]/2;j++)
				l.PB('a'+i);
		r = l;
		reverse(ALL(r));
		cout << l << r << endl;
	}
	
}