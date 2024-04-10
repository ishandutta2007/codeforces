#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int T,n,a[N],fl;
void solve(){
	scanf("%d",&n);fl=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)if(abs(a[i+1]-a[i])>1){
		puts("YES");printf("%d %d\n",i,i+1);fl=1;break; 
	}
	if(!fl)puts("NO");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}