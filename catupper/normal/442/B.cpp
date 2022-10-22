#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

double ans, p[1080];
int n;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%lf", &p[i]);
		if(p[i] == 1.0){
			cout << 1 << endl;
			return 0;
		}
	}
	sort(p, p + n);
	for(int i = n - 1;i >= 0;i--){
		for(int j = i;j >= 0;j--){
			double pp = 0, res = 1;
			for(int k =i;k >= j;k--){
				pp += p[k] / (1 - p[k]);
				res *= 1 - p[k];
			}
			ans = max(ans, res * pp);
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}