#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, p;
int a[101000], b[101000];

int main(){
	scanf("%d%d", &n, &p);
	ll sum = 0;
	for(int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i), sum += a[i];
	if(sum <= p){
		printf("-1\n");
	}else{
		double l = 0, r = 1e11;
		for(int i = 1; i <= 300; ++i){
			double d = (l + r) / 2, sum = 0;
			for(int j = 1; j <= n; ++j)
				if(a[j] * d > b[j]) sum += a[j] * d - b[j];
			if(sum <= p * d) l = d;
			else r = d;
		}
		printf("%.10f\n", l);
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}