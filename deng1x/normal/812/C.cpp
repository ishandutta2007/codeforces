#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int a[N];
ll num[N];
int n, s;

ll check(int mid){
	for (int i = 1; i <= n; ++ i){
		num[i] = a[i] + 1ll * mid * i;
	}
	std::sort(num + 1, num + n + 1);
	ll sum = 0;
	for (int i = 1; i <= mid; ++ i){
		sum += num[i];
	}
	return sum;
}

int main(){
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	int left = 0, right = n;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (check(mid) <= s){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	return printf("%d %I64d\n", left, check(left)), 0;
}