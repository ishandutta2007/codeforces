#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
typedef long long Int;

double  a[108000], b[108000], asum, bsum;
int n, m;
int main(){
	cin >> m >> n;
	for(Int i = 0;i < m;i++){
		scanf("%lf", a + i);
		asum += a[i];
	}
	for(Int i = 0;i < n;i++){
		scanf("%lf", b + i);
		bsum += b[i];
	}
	sort(a, a + m);
	for(Int i = 1;i < m;i++)a[i] += a[i - 1];
	sort(b, b + n);                          
	for(Int i = 1;i < n;i++)b[i] += b[i - 1];
	
	double res = min(asum * n, bsum * m);
	for(Int i = m - 1;i > 0;i--){
		res = min(res, (m - i) * bsum + a[i - 1]);
	}
	for(Int i = n - 1;i > 0;i--){
		res = min(res, (n - i) * asum + b[i - 1]);
	}
	cout << (Int)(res + 0.5) << endl;
	
}