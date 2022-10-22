#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;

int n, k, vec[MAXN], ss[MAXN];
int prv[MAXN], nxt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];

	prv[0] = nxt[n - 1] = -1;
	for (int i = 1; i < n; i++)
		if (vec[i] == vec[i - 1])
			prv[i] = prv[i - 1];
		else
			prv[i] = vec[i - 1];
	for (int i = n - 2; i >= 0; i--)
		if (vec[i] == vec[i + 1])
			nxt[i] = nxt[i + 1];
		else
			nxt[i] = vec[i + 1];

	for (int i = 0; i < n; i++){
		if (i != 0 && vec[i] == vec[i - 1])	continue;
		if (prv[i] != nxt[i] && nxt[i] != -1 && prv[i] != -1){
			ss[vec[i]]++;
			continue;
		}
		if (nxt[i] == -1 && prv[i] == -1)	continue;

		if (nxt[i] == -1 || prv[i] == -1)
			ss[vec[i]]++;
		else
			ss[vec[i]] += 2;
	}
	
	int mini = -1, ans;
	for (int i = 1; i <= k; i++)
		if (mini < ss[i]){
			ans = i;
			mini = ss[i];
		}
	cout << ans << endl;
	return 0;
}