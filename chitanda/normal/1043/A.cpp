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
int a[111];

bool check(int k){
	int tmp1 = 0, tmp2 = 0;
	for(int i = 1; i <= n; ++i)
		tmp1 += a[i], tmp2 += k - a[i];
	return tmp1 < tmp2;
}

int main(){
	scanf("%d", &n);
	int k = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		k = max(k, a[i]);
	}
	
	while(!check(k)) ++k;

	printf("%d\n", k);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}