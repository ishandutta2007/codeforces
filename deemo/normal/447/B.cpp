#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 20;

string s;
int k, v[300];
ll ans;

int main(){
	cin >> s >> k;
	int maxi = 0;
	for (int i = 'a'; i <= 'z'; i++){
		cin >> v[i];
		maxi = max(maxi, v[i]);
	}
	for (int i = 0; i < s.size(); i++)
		ans += v[s[i]] * (i + 1);
	for (int i = s.size(); i < s.size() + k; i++)
		ans += maxi * (i + 1);
	cout << ans << endl;
	return	0;		
}