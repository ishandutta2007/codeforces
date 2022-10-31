#include<bits/stdc++.h>
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define R register
#define endl putchar('\n')
const int N=50005;
using namespace std;

int n;

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		printf("%d\n",(n-9)/10+(n>=9));
	}
	return 0;
}