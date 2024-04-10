#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int cnt[30010 * 4];
int a[30010 * 4], b[30010 * 4], c[30010 * 4], w[30010 * 4];

int main(){
	scanf("%d", &n);
	queue<int> q;
	for(int i = 1; i <= 4 * n; ++i){
		scanf("%d%d%d", a + i, b + i, c + i);
		//q.push(i);
		w[i] = i;
	}
	random_shuffle(w + 1, w + 4 * n + 1);
	for(int i = 1; i <= 4 * n; ++i)
		q.push(w[i]);
	vector<int> ans;
	while(!q.empty()){
		int t = q.front(); q.pop();
		--cnt[a[t]];
		++cnt[b[t]];
		++cnt[c[t]];
		if(cnt[b[t]] <= 5 && cnt[c[t]] <= 5) ans.pb(t);
		else{
			++cnt[a[t]];
			--cnt[b[t]];
			--cnt[c[t]];
			q.push(t);
		}
	}
	printf("YES\n");
	for(auto v : ans) printf("%d ", v);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}