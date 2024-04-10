#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define F0R(i, a) for (int i=0; i<a; i++)
 
const int MAXN = 201000;
ll n,k,z;
int sign, coef[MAXN], sum[MAXN];

void add(int ind, int val) {
	sum[ind] += val;
	if (sum[ind] < 0) {
		int x = (-sum[ind]+1)/2;
		sum[ind] += 2*x;
		add(ind+1,-x);
	} else if (sum[ind] > 1) {
		int x = sum[ind]/2;
		sum[ind] -= 2*x;
		add(ind+1, x);
	}
}

int main() {
	int ans = 0;
	sum[MAXN-1] = 1;
	cin >> n >> k;
	F0R(i,n+1) scanf("%d",&coef[i]), sum[i] = coef[i];
	F0R(i,n+1) if (sum[i] < 0 || sum[i] > 1) add(i,0);
	
	int low, high = MAXN-1;
	F0R(i,MAXN) if(sum[i] == 1) {
		low = i;
		break;
	}
	
	if (sum[MAXN-1] == 1) {
		sign = 1;
		sum[MAXN-1] = 0;
		while (sum[high] == 0) high--;
	} else {
		for (int i = MAXN-2; i >= 0; --i) if (sum[i] == 1) sum[i] = 0;
		else sum[i] = 1;
		add(0,1);
		for (int i = MAXN-2; i >= 0; --i) if (sum[i] == 1) {
			high = i;
			break;
		}
	}
	int ind = low;
	ll sum1 = 0;
	if (high-ind<40) for (int i = high; i >= low; --i) {
		sum1 *= 2;
		sum1 += sum[i];
	}
	
	while (high-ind<40 && ind >= 0) {
		if (ind <= n) {
			if (sign == 1) z = (ll)coef[ind]-sum1;
			else z = (ll)coef[ind]+sum1;
			if (abs(z) <= k && (ind != n || (z != 0))) ans++; 
		}
		ind --, sum1 *= 2;
	}
	cout << ans;
}