#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll suf[20000005],ans=0;
ll a[200004],b[200004];
ll getsuf(int L,int R){
	return L==0?suf[R]:suf[R]-suf[L-1];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),suf[i*100]+=a[i];
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=100*n;i++)suf[i]+=suf[i-1];
	int it=0;
	for(int i=0;i<=400*n;i++){
		while(it<m&&b[it+1]*4<=i)it++;
		if(it>0&&b[it]*4==i)continue;
		ll L=0,R=100*n;
		if(it>0){
			ll tmp=4*b[it]+i;
			L=(tmp+8)/8;
		}
		if(it<m){
			ll tmp=4*b[it+1]+i-1;
			R=tmp/8;
		}
		if(R>100*n)R=100*n;
		if(L<=R)ans=max(ans,getsuf(L,R));
	}
	printf("%lld",ans);
}