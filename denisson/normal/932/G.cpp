#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 7;

string s;

struct tree{
	string s;
	int to[26][1000007];
	int suf[1000007];
	int slink[1000007];
	int diff[1000007];
	int len[1000007];
	int last;
	int sz;
	tree() { s = "#"; for (int i = 0; i < 26; i++) for (int j = 0; j < 1000007; j++) to[i][j] = -1; sz = 2; last = 1; len[0] = -1; suf[1] = 0; suf[0] = -1; }

	void add(char c){
		s += c;
		while(c != s[(int)s.size() - len[last] - 2]) last = suf[last];
		if (to[c - 'a'][last] == -1){
			int v = sz++;
			to[c - 'a'][last] = v;
			len[v] = len[last] + 2;
			do { last = suf[last]; } while(last != -1 && s[(int)s.size() - len[last] - 2] != c);
			if (last == -1){
				suf[v] = 1;
			} else {
				suf[v] = to[c - 'a'][last];
			}
			diff[v] = len[v] - len[suf[v]];
			if (diff[v] == diff[suf[v]])
				slink[v] = slink[suf[v]];
			else
				slink[v] = suf[v];
			last = v;
		} else last = to[c - 'a'][last];
	}
} tr;

int dp[1000007];
int dpKek[1000007];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int main(){
   	//freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
 	cin >> s;
 	string t;
 	for (int i = 0; i < s.size(); i++){
 		if (i % 2 == 0){
 			t += s[i / 2];
 		} else {
 			t += s[(int)s.size() - i / 2 - 1];
 		}
 	}

 	//cout << t << endl;

 	dp[0] = 1;
 	for (int i = 1; i <= t.size(); i++){
 		char c = t[i - 1];
 		tr.add(c);
		for (int v = tr.last; v > 1; v = tr.slink[v]){
			dpKek[v] = dp[i - tr.len[tr.slink[v]] - tr.diff[v]];
			if (tr.diff[v] == tr.diff[tr.suf[v]]) add(dpKek[v], dpKek[tr.suf[v]]);
			add(dp[i], dpKek[v]);
		}
 		if (i % 2 == 1){
 			dp[i] = 0;
 		}
 		//cout << i << ' ' << dp[i] << endl;
 	}
 	cout << dp[t.size()];
}