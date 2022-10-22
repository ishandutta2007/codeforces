#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int b,k,a[maxn];
int main(){
	scanf("%d%d",&b,&k);
	for(int i = 1;i <= k;i++) scanf("%d",&a[i]);
	if(b & 1){
		int ans = 0;
		for(int i = 1;i <= k;i++) ans ^= a[i] & 1;
		if(ans) puts("odd");
		else puts("even");
	}else{
		if(a[k] & 1) puts("odd");
		else puts("even");
	}
	return 0;
}