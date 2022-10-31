#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int n,U;
int e[maxn];
void input(){
	scanf("%d%d",&n,&U);
	for (int i=0;i<n;i++){
		scanf("%d",e+i);
	}
}
void solve(){
	double ans =0;
	for (int i=0;i<n-2;i++){
		int j = lower_bound(e,e+n,e[i]+U)-e;
		if (j==n)continue;
		if (e[j]!=e[i]+U)j--;
		if (j<=i+1)continue;
		ans = max(ans,1.0*(e[j]-e[i+1])/(e[j]-e[i]));
	}
	for (int i=n-3;i>=0;i--){
		if (e[n-1]-e[i]>U)break;
		ans = max(ans,1.0*(e[n-1]-e[i+1])/(e[n-1]-e[i]));
	}
	if (ans==0)printf("-1\n");
	else{
		printf("%.9f\n",ans);
	}
}
int main(){
	input();
	solve();
	return 0;
}