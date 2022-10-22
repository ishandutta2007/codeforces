#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int XX = (1<<10) + 10;

int n, k, x;
int cnt[XX], cnt2[XX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		cnt[temp]++;
	}
	while (k--){
		memset(cnt2, 0, sizeof(cnt2));
		int cur = 0;
		for (int i = 0; i < XX; i++){
			int temp = 0;
			if (!(cur&1))
				temp = cnt[i]+1>>1;
			else
				temp = cnt[i]>>1;
			cnt2[i] += cnt[i]-temp;
			cnt2[i^x] += temp;
			cur += cnt[i];
		}
		memcpy(cnt, cnt2, sizeof(cnt2));
	}
	for (int i = XX-1; ~i; i--)
		if (cnt[i]){
			cout << i << " ";
			break;
		}
	for (int i = 0; i < XX; i++)
		if (cnt[i]){
			cout << i << "\n";
			break;
		}
	return 0;
}