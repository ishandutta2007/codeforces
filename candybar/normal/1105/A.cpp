#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn];
int calc(int t){
	int res = 0;
	for(int i=1;i<=n;i++){
		if(a[i] < t) res += t - 1 - a[i];
		else if(a[i] > t) res += a[i] - t - 1;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int ans = 0,val = 0x3f3f3f3f;
	for(int i=1;i<=100;i++){
		if(calc(i) < val){
			val = calc(i);
			ans = i;
		}
	}
	printf("%d %d\n",ans,val);
	return 0;
}