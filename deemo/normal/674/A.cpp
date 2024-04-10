#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e4 + 10;

int n, vec[MAXN], cnt[MAXN], cc[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> vec[i], vec[i]--;
	for (int i = 0; i < n; i++){
		memset(cnt, 0, sizeof(cnt));
		int mx = 0, ind = 0;
		for (int j = i; j < n; j++){
			cnt[vec[j]]++;
			if (cnt[vec[j]] > mx){
				ind = vec[j];
				mx = cnt[vec[j]];
			}	
			else if (cnt[vec[j]] == mx)
				ind = min(ind, vec[j]);
			cc[ind]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << cc[i] << " ";
	cout << "\n";
	return 0;
}