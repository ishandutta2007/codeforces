#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=1<<20|5;
inline void mo(int& x){x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int a[N],pw2[N],cnt[N];
void FWT(int a[],int n){
	for(int s=1,sx=2;s<n;sx=(s=sx)<<1)
		for(int i=0;i<n;i+=sx)
			for(int j=i;j<i+s;++j)
				mo(a[j]+=a[j+s]);
}
int main(){
	pw2[0]=1; 
	for(int i=1;i<N;++i)
		mo(pw2[i]=pw2[i-1]<<1);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		a[x]++;
	}
	FWT(a,1<<20);
	cnt[0]=0;
	int ans=0;
	for(int i=0;i<1<<20;++i){
		if(i>0) cnt[i]=cnt[i-(i&-i)]+1;
		if(cnt[i]&1) mo(ans+=MOD-pw2[a[i]]);
		else mo(ans+=pw2[a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}