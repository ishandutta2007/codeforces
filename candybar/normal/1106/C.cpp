#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 300005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	ll res = 0;
	for(int i=1;i<=n/2;i++){
		res += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
	}
	printf("%I64d\n",res);
	return 0;
}