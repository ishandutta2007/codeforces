#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

int n;
double prob[108000], ans;
int x[108000], y[108000];
int x1, x2, y1, y2;

int main(){
	cin >> n;
	prob[0] = 1;
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
		prob[i+1] = prob[i] / 2.0;
	}	
	
	ans -= n / 2.0 / 2.0;      //Vertex
	ans += n * prob[n] / 2.0;  //Vertex
	ans += n * (n-1) * prob[n] / 2.0;  //Vertex
	int m = min(100, n - 1);

	for(int i = 1;i < m;i++){
		for(int j = 0;j < n;j++){
			x1 = x[j];y1 = y[j];
			x2 = x[(i+j)%n];y2 = y[(i+j)%n];
			ans += (prob[i+1] - prob[n]) * ((double)x1*y2 - (double)x2*y1) / 2;//Area
			ans -= (prob[i+1] - prob[n]) * (__gcd(abs(x1 - x2), abs(y1 - y2)) - 1) / 2;//Outside
		}
	}
	double res = 0;
	
	ans /= 1 - (1 + n + n*(n-1)/2)*prob[n];
	printf("%.10f\n", ans + 1);
	return 0;	
}