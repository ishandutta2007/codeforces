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
int a[1010], b[1010], c[1010], d[1010], e[1010];

int sum(int a, int a1, int b, int b1, int c, int c1, int d, int d1, int e, int e1){
	return a * a1 + b * b1 + c * c1 + d * d1 + e * e1;
}

bool check(int i, int j, int k){
	int tmp = sum(a[j] - a[i], a[k] - a[i], b[j] - b[i], b[k] - b[i], c[j] - c[i], c[k] - c[i], d[j] - d[i], d[k] - d[i], e[j] - e[i], e[k] - e[i]);
	return tmp > 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d%d%d%d", a + i, b + i, c + i, d + i, e + i);
	/*
	for(int i = 1; i <= n; ++i)
	t[i] = a[i] * a[i] + b[i] * b[i] + c[i] * c[i] + d[i] * d[i] + e[i] * e[i];*/
	
	if(n > 100) printf("%d\n", 0);
	else{
		vector<int> ans;
		for(int i = 1; i <= n; ++i){
			bool flag = 1;
			for(int j = 1; j < n && flag; ++j)
				for(int k = j + 1; k <= n && flag; ++k)
					if(i != j && i != k){
						if(check(i, j, k))
							flag = 0;
					}
			if(flag) ans.pb(i);
		}
		printf("%d\n", (int)ans.size());
		for(auto v : ans)
			printf("%d\n", v);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}