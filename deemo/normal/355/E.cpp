#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 3e5 + 10;
const int MAXVAL = 1e6 + 10;

int n, k, vec[MAXN], mx = 0;

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		mx = max(mx, vec[i]);
	}
	sort(vec, vec + n);
	for (int i = mx; i; i--){
		int cur = 0;
		for (int j = i; j <= mx; j += i){
			int p1 = lower_bound(vec, vec + n, j) - vec;
			int p2 = upper_bound(vec, vec + n, j + k) - vec;
			if (p1 > cur)	break;
			cur = p2;
		}

		if (cur == n){
			printf("%d\n", i);
			return	0;
		}
	}
	return	0;
}