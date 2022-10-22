#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

ll n, vec[MAXN], s1, sec[MAXN], s2;
ll a[MAXN];
map<ll, int> mp, cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 50; i++) mp[1ll<<i] = i;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	while (cnt[1]){
		int cur = 0; cnt[1]--;
		while (cnt[1ll<<cur+1]){
			cur++;
			cnt[1ll<<cur]--;
		}
		vec[s1++] = cur;
	}
	sort(vec, vec + s1);
	reverse(vec, vec + s1);

	for (auto x:cnt)
		while (x.S--)
			sec[s2++] = x.F;

	sort(sec, sec + s2);
	reverse(sec, sec + s2);

	if (s1 < s2){
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < s2; i++)
		if ((1ll<<vec[i]+1) < sec[i]){
			cout << "-1\n";
			return 0;
		}

	int temp = 0, rem = s1-s2;
	for (int j = s1-1; j >= s2; j--){
		rem--;
		if (rem < vec[j]+1) break;
		rem -= vec[j]+1;
		temp++;
	}

	for (int l = s1 - temp; l <= s1; l++)
		cout << l << " ";
	cout << "\n";
	return 0;
}