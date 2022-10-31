#include <stdio.h>
int BITS = 10;

int ask[2000],sz;

int main() {
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);

	int dif[BITS];
	int A=0,B=0;
	int diff_loc = 0;
	for(int b = 0; b < BITS; ++b) {
		sz = 0;
		for(int i = 1; i <= n; ++i)
			if(i & (1<<b)) ask[sz++] = i;
		int res;
		if(sz != 0) {
			printf("?");
			printf(" %d",sz);
			for(int i = 0; i < sz; ++i)
				printf(" %d",ask[i]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&res);
		} else res = 0;
		if(res == y || res == (x ^ y)) {
			dif[b] = 1;
			diff_loc = b;
		} else
			dif[b] = 0;
	}
	B ^= (1<<diff_loc);
	for(int b = 0; b < BITS; ++b) {
		if(b == diff_loc) continue;
		//find B
		sz = 0;
		for(int i = 1; i <= n; ++i) {
			if((i & (1<<b)) && (i & (1<< diff_loc)))
				ask[sz++] = i;
		}
		int res;
		if(sz != 0) {
			printf("?");
			printf(" %d",sz);
			for(int i = 0; i < sz; ++i)
				printf(" %d",ask[i]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&res);
		} else res = 0;
		if(res == y || res == (x ^ y)) {
			B ^= (1<<b);
			if(!dif[b]) A ^= (1<<b);
		} else if(dif[b]) A ^= (1<<b);
	}
	printf("! %d %d\n",A,B);
	fflush(stdout);
}