#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 2e9 + 2;
const int MAX = 1e7 + 10;

int n, m;
int vec[MAXN], sec[MAXN];
int cnt[MAXN], mini[MAXN];

int dis(int a, int b){
	if (b >= m)	return	INF;
	return	abs(vec[a] - sec[b]);	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		int t1, t2;
		cin >> n >> m >> t1 >> t2;
	}
	for (int i = 0; i < n; i++)
		cin >> vec[i], vec[i] += MAX;
	for (int i = 0; i < m; i++)
		cin >> sec[i], sec[i] += MAX;

	fill(mini, mini + MAXN, INF);
	int b = 0;
	for (int i = 0; i < n; i++){
		while (dis(i, b) > dis(i, b + 1))	b++;
		
		if (dis(i, b) != dis(i, b + 1)){
			if (mini[b] == dis(i, b))
				cnt[b]++;
			else if (mini[b] > dis(i, b)){
				cnt[b] = 1;
				mini[b] = dis(i, b);
			}
		}
		else{
			if (cnt[b] == 0 || mini[b] == dis(i, b))
				cnt[b]++;
			else{
				cnt[b + 1] = 1;
				mini[b + 1] = dis(i, b + 1);
			}
		}	
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans += cnt[i];
	cout << endl;
	cout << n - ans << endl;
	return 0;	
}