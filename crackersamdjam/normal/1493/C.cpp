#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int t, n, k;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n>>k>>s;
		if(n%k){
			cout<<"-1\n";
			continue;
		}
		//try each letter as "inc" pt
		vector<int> cnt(26);
		pair<int, char> best = {-1, -1};
		for(int i = 0; i < n; i++){
			for(int c = s[i]-'a'+1; c < 26; c++){
				int req = 0;
				cnt[c]++;
				for(int j = 0; j < 26; j++){
					req += (k-cnt[j]%k)%k;
				}
				if(req <= n-1-i){
					best = max(best, {i, -c});
				}
				cnt[c]--;
			}
			cnt[s[i]-'a']++;
		}
		int ok = 1;
		for(int i = 0; i < 26; i++){
			if(cnt[i]%k){
				ok = 0;
				break;
			}
		}
		if(ok){
			cout<<s<<'\n';
			continue;
		}

		assert(best.first != -1);

		cnt.assign(26, 0);
		for(int i = 0; i < n; i++){
			if(i == best.first){
				best.second = -best.second;
				cnt[best.second]++;
				string t = s.substr(0, i);
				t += (best.second+'a');
				string u;
				for(char j = 25; j >= 0; j--){
					int rem = (k-cnt[j]%k)%k;
					while(rem--)
						u += (j+'a');
				}
				while(size(t)+size(u) < n){
					u += 'a';
				}
				reverse(all(u));
				t += u;
				cout<<t<<'\n';
				break;
			}
			cnt[s[i]-'a']++;
		}
	}
}