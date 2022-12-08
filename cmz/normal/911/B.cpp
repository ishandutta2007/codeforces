#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	int maxx=min(m,k);
	for(int i=maxx; i>=1; i--) {
		int res=m/i+k/i;
		if(res>=n) {
			printf("%d",i);
			break;
		}
	}
	return 0;
}