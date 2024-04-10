#include<iostream>
#include<string>

using namespace std;

const int max_n = 1e6 + 10;

string s;
int p[max_n], cnt[max_n], k;
long long ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> s;
	int n = s.size();

	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			p[i + 1] = p[i] + 1;
		else
			p[i + 1] = p[i];

	cnt[0] = 1;
	for (int i = 0; i < n; i++){
		if (p[i + 1] < k){
			cnt[p[i + 1]]++;
			continue;
		}

		ans += cnt[p[i + 1] - k];
		cnt[p[i + 1]]++;
	}
	
	cout << ans << endl;
	return 0;
}