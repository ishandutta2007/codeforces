#include <bits/stdc++.h>

using namespace std;

string ans, res;
multiset <string> ST[110];
int n;

void ask(int L, int R, int ok){
	cout << '?' << ' ' << L << ' ' << R << endl;
	int N = (R - L + 1) * (R - L + 2) / 2;
	for(int i=1; i<=N; i++){
		string t;
		cin >> t;
		int sz = t.size();
		sort(t.begin(), t.end());
		if(ok) ST[sz].insert(t);
		else ST[sz].erase(ST[sz].find(t));
		if(n == 1){
			cout << '!' << ' ' << t[0] << endl;
			exit(0);
		}
	}
}

int cnt[26];

int main() {
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int p = (n + 1) / 2, q = n - p;
	ask(1, p, 1);
	if(p != 1) ask(2, p, 0);
	for(int i=1; i<=p; i++){
		string t = *ST[i].begin();
		for(int j=0; j<t.size(); j++){
			cnt[t[j] - 'a']++;
		}
		for(int j=0; j<26; j++){
			if(cnt[j]){
				ans += 'a' + j;
				break;
			}
		}
		memset(cnt, 0, sizeof cnt);
		for(int j=0; j<t.size(); j++){
			cnt[t[j] - 'a']--;
		}
		ST[i].clear();
	}
	ask(1, n, 1);
	string tot = *ST[n].begin();
	
	for(int i=1; i<=q; i++){
		int x = n - i;
		for(int L=1; L<=n-x; L++){
			int R = L + x - 1;
			memset(cnt, 0, sizeof cnt);
			for(int j=0; j<tot.size(); j++){
				cnt[tot[j] - 'a']++;
			}
			for(int j=0; j<L; j++){
				cnt[ans[j] - 'a']--;
			}
			for(int j=0; j<n-R-1; j++){
				cnt[res[j] - 'a']--;
			}
			string t;
			for(int j=0; j<26; j++){
				while(cnt[j]){
					cnt[j]--;
					t += 'a' + j;
				}
			}
			ST[x].erase(ST[x].find(t));
		}
		string t = *ST[x].begin();
		memset(cnt, 0, sizeof cnt);
		for(int j=0; j<tot.size(); j++){
			cnt[tot[j] - 'a']++;
		}
		for(int j=0; j<t.size(); j++){
			cnt[t[j] - 'a']--;
		}
		for(int j=0; j<res.size(); j++){
			cnt[res[j] - 'a']--;
		}
		for(int j=0; j<26; j++){
			if(cnt[j]){
				res += 'a' + j;
				break;
			}
		}
	}
	for(int i=res.size()-1; i>=0; i--){
		ans += res[i];
	}
	cout << '!' << ' ' << ans << endl;
}