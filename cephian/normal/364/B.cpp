#include <bits/stdc++.h>
using namespace std;

const int V = 500005;
bool ok[V]={};

int main() {	
	int n,d;
	scanf("%d%d",&n,&d);
	ok[0] = 1;
	while(n--) {
		int a;
		scanf("%d",&a);
		for(int i = V-1; i >= a; --i)
			ok[i] |= ok[i-a];
	}
	int i = 0, ans = 0;
	while(1) {
		int j = i + d;
		while(j >= V || !ok[j]) --j;
		if(i == j) break;
		i = j;
		++ans;
	}
	printf("%d %d\n",i,ans);
}