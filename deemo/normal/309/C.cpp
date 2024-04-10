#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

const int MAXN = 1e6 + 10;
const int LOG = 30 + 1;

int n, m, vec[MAXN], cnt[LOG + 2];
priority_queue<int, vector<int>, greater<int>> st;

int main(){
	scanf("%d %d", &n, &m);
	while (n--){
		int x;	scanf("%d", &x);
		for (int i = LOG - 1; i >= 0; i--)
			if ((x >> i) & 1)	cnt[i]++;
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &vec[i]);
	sort(vec, vec + m);
	int ans = 0;
	for (int i = 0; i < m; i++){
		for (int j = vec[i]; j < LOG; j++)
			if (cnt[j]){
				ans++;
				cnt[j]--;
				for (int w = vec[i]; w < j; w++)
					cnt[w]++;
				break;
			}
	}
	printf("%d\n", ans);
	return	0;
}