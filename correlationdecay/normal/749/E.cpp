#include <bits/stdc++.h>
#define maxn 100009
using namespace std;
int n;
int a[maxn];
long long L[maxn], R[maxn], b[maxn], tot;
double sum[maxn];
void update(int x, int val){
	while(x < maxn){
		b[x] += val;
		x += x & -x;
	}
}
long long getsum(int x){
	long long sum = 0;
	while(x > 0){
		sum += b[x];
		x -= x & -x;
	}
	return sum;
}

double prefix(){
	double ans = 0;
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; i++){
		ans += 1.0 * (getsum(n) - getsum(a[i])) * (n - i + 1);
		update(a[i], i);
	}
	return ans;
}

double suffix(){
	memset(b, 0, sizeof(b));
	for(int i = n; i >= 1; i--){
		R[i] = R[i + 1] + getsum(a[i] - 1);
		update(a[i], 1);
	}
	return R[1];
}

double sum1(double L, double R){
	return (L + R) * (R - L + 1) / 2;
}	
double sum2(double L, double R){
	L = L - 1;
	return R * (R + 0.5) * (R + 1) / 3 - L * (L + 0.5) * (L + 1) /3;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	double ans = - prefix() / n / (n + 1) * 2;

	ans = ans + suffix();

	for(double i = 1; i <= n; i= i +1){
		double cur = 0;
		cur = 0.25 * sum2(i, n) + 0.25 * (1 - 2 * i) * sum1(i, n) + 0.25 * (n - i + 1) * 1.0 * (i * i - i);
		ans = ans + 1.0 / n / (n + 1) * 2 * cur;
	}

	printf("%.15f\n",ans);
	//system("pause");
	return 0;
}