#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e6 + 10;

int n, q, ss[2], p[MAXN];

int main(){
	scanf("%d %d", &n, &q);

	bool cur = 0;
	int z = 0;
	while (q--){
		int t;	scanf("%d", &t);
		if (t == 1){
			int x;scanf("%d", &x);
			z = (z + x) % n;
			x = abs(x);
			if (x & 1)
				cur = !cur;
		}
		else{
			if (cur)
				ss[1]++, ss[0]--;
			else
				ss[0]++, ss[1]--;
			cur = !cur;
		}
	}
	
	for (int i = 0; i < n; i++){
		int pos = i;
		pos += z + ss[i & 1];
		pos %= n;
		if (pos < 0)	pos += n;
		p[pos] = i + 1;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}