#include <cstdio>
#include <algorithm>
#define int long long

using namespace std;

struct Node{
	int id;
	long long val;	
} arr[200005];

bool Comp(const Node &a, const Node &b){
	return a.val < b.val;
}

main(){
	int n; scanf("%lld", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i].val), arr[i].id = i;
	sort(arr, arr + n, Comp);
	long long del = arr[1].val - arr[0].val; int lst = 1, wz = -1; bool is_dead = true;
	for (int i = 2; i < n; ++i){
		if (arr[i].val - arr[lst].val != del){
			if (wz != -1){is_dead = false;break;}
			wz = arr[i].id;
		}
		else lst = i;
	}
	if (is_dead){
		if (wz == -1) wz = arr[0].id;
		printf("%d", wz + 1);
		return 0;
	}
	del = arr[2].val - arr[0].val, is_dead = true;
	for (int i = 3; i < n; ++i){
		if (arr[i].val - arr[i - 1].val != del){is_dead = false;break;}
	}
	if (is_dead){
		printf("%d", arr[1].id + 1);
		return 0;
	}
	del = arr[2].val - arr[1].val, is_dead = true;
	for (int i = 3; i < n; ++i){
		if (arr[i].val - arr[i - 1].val != del){is_dead = false;break;}
	}
	if (is_dead){ printf("%d", arr[0].id + 1); return 0;}
	printf("-1");
	return 0;
}