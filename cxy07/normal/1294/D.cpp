//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 10;

int q,x,mex = 0;
int cnt[MAXN];

int main () {
	scanf("%d%d",&q,&x);
	while(q--) {
		int tmp;
		scanf("%d",&tmp);
		cnt[tmp % x]++;
		while(cnt[mex % x]) {
			cnt[mex % x]--;
			mex++;
		}
		printf("%d\n",mex);
	}
	return 0;
}