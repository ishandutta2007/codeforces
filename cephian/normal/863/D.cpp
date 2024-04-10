#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N],n,q,m;
int t[N],l[N],r[N];

int main() {	
	scanf("%d%d%d",&n,&q,&m);
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	for(int i = 0; i < q; ++i)
		scanf("%d%d%d",t+i,l+i,r+i),--l[i],--r[i];
	for(int i = 0; i < m; ++i) {
		int b;
		scanf("%d",&b),--b;
		for(int j = q-1; j >= 0; --j) {
			if(t[j] == 1) {
				if(l[j] < b && b <= r[j]) --b;
				else if(b == l[j]) b = r[j];
			} else if(l[j] <= b && b <= r[j]){
				b = r[j]-(b-l[j]);
			}
		}
		printf("%d ",a[b]);
	}
	printf("\n");
}