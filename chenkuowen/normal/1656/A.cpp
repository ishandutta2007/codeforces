#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int a[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		int p1=1,p2=1;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]<a[p1]) p1=i;
			if(a[i]>a[p2]) p2=i;
		}
		printf("%d %d\n",p1,p2);
	}
	return 0;
}