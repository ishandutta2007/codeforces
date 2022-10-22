//Where are you, hatter?

#include<bits/stdc++.h>

using namespace std;

int n, cnt[10];
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	for (char c:t)
		cnt[c - '0']++;
	
	int ans = 0;
	for (char c:s){
		bool done = 0;
		for (int i = (int)(c - '0'); i < 10; i++)
			if (cnt[i]){
				cnt[i]--;
				done = 1;
				break;
			}
		if (!done){
			ans++;
			for (int i = 0; i < 10; i++)
				if (cnt[i]){
					cnt[i]--;
					break;
				}
		}
	}
	cout << ans << "\n";

	ans = 0;
	for (char c:t)
		cnt[c - '0']++;

	for (char c:s){
		bool done = 0;
		for (int i = (int)(c - '0')+1; i < 10; i++)
			if (cnt[i]){
				cnt[i]--;
				done = 1;
				break;
			}
		if (!done){
			for (int i = 0; i < 10; i++)
				if (cnt[i]){
					cnt[i]--;
					break;
				}
		}
		else ans++;
	}

	cout << ans << "\n";
	return 0;
}