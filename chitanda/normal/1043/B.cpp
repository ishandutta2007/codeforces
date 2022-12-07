#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

int n;
int a[1111], b[1111], p[1111];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		b[i] = a[i] - a[i - 1];
	}

	int j = 0;
	for(int i = 2; i <= n; ++i){
		while(j && b[j + 1] != b[i]) j = p[j];
		if(b[j + 1] == b[i]) ++j;
		p[i] = j;
	}

	int cur = n;
	int cnt = 0;
	vector<int> res;
	while(p[cur]){
		res.pb(n - p[cur]);
		++cnt;
		cur = p[cur];
	}

	printf("%d\n", cnt + 1);
	for(int  v : res) printf("%d ", v);
	printf("%d", n);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}