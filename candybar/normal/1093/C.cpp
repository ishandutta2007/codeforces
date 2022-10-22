#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll b[maxn],a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n / 2;i++) scanf("%I64d",&b[i]);
	a[1] = 0, a[n] = b[1];
	for(int i=2;i<=n / 2;i++){
		a[i] = a[i - 1];
		a[n - i + 1] = a[n - i + 2];
		if(a[i] + a[n - i + 1] > b[i]) a[n - i + 1] = b[i] - a[i];
		else a[i] = b[i] - a[n - i + 1];
	}
	for(int i=1;i<=n;i++) printf("%I64d%c",a[i],i == n ? '\n' : ' ');
	return 0;
}