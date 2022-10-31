#include <cstdio>
#include <cmath>
using namespace std;

int readMax(){
	int n;
	scanf("%d", &n);
	int ret = -1;
	int x;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		if (x > ret) ret = x;
	}
	return ret;
}
int readMin(){
	int n;
	scanf("%d", &n);
	int ret = 31337;
	int x;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		if (x < ret) ret = x;
	}
	return ret;
}
double computeR2(int r1, int p1, int p2, int a, int b){
	return sqrt(1.0 * p1 / (1.0 * p2 * a / b + p1)) * r1;
}
int main(){
	int r1 = readMax();
	int p1 = readMax();
	int p2 = readMin();
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%f", computeR2(r1, p1, p2, a, b));
}