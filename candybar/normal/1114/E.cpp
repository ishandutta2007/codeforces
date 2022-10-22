#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1000005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt;
int q_large(int x){
	cnt++;
	printf("> %d\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}
int q_val(int x){
	cnt++;
	printf("? %d\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}
int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x % y);
}
int a[65];
bool app[maxn];
void gen(int len){
	for(int i = 1;i <= len;i++){
		int pos = ((ll)rand() * rand() + rand()) % n + 1;
		app[pos] = true;
		a[i] = q_val(pos);
	}
	sort(a + 1,a + len + 1);
}
int main(){
	srand(25235);
	scanf("%d",&n);
	int lb = 0, rb = (int)1e9;
	while(lb < rb){
		int mid = (lb + rb) >> 1;
		if(q_large(mid)) lb = mid + 1;
		else rb = mid;
	}
	int maxi = lb, len = 60 - cnt;
	gen(len);
	a[++len] = maxi;
	int d = 0;
	for(int i = 2;i <= len;i++){
		d = gcd(d,a[i] - a[i - 1]);
	}
	printf("! %d %d\n",maxi - (n - 1) * d,d);
	fflush(stdout);
	return 0;
}