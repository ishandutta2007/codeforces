#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int A, B, n;
int l, t, m;
ll s0;

bool check(int d){
	ll sum = s0 * (d + 1) + (ll)d * (d + 1) / 2 * B;
	ll last = s0 + (ll)d * B;
	if(last > t) return 0;
	return sum <= (ll)t * m;
}

int main(){
	scanf("%d%d%d", &A, &B, &n);
	while(n--){
		scanf("%d%d%d", &l, &t, &m);
		s0 = A + (ll)(l - 1) * B;
		if(s0 > t){
			printf("%d\n", -1);
			continue;
		}
		int lt = 0, rt = 1000000;
		while(lt + 1 < rt){
			int d = (lt + rt) >> 1;
			if(check(d)) lt = d;
			else rt = d;
		}
		printf("%d\n", l + lt);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}