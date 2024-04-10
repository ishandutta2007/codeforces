#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

int n;

void work(vector<int> q, int n){
	if(!n) return;
	int mx = 0;
	//for(auto v : q) printf("%d ", v); puts("");
	for(int i = 0; i < q.size() - 1; ++i)
		if(abs(q[i] - q[i + 1]) > 1){
			puts("NO");
			//system("pause");
			exit(0);
		}
	for(int i = 0; i < n; ++i) mx = max(mx, q[i]);
	for(int i = 0; i < n; ++i)
		if(mx == q[i]){
			vector<int> qq;
			for(int j = 0; j < q.size(); ++j)
				if(j != i) qq.pb(q[j]);
			work(qq, n - 1);
			return;
		}
}

int main(){	
	scanf("%d", &n);
	vector<int> q;
	for(int i = 1, x; i <= n; ++i){
		scanf("%d", &x);
		q.pb(x);
	}
	work(q, n);
	printf("YES");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}