#include<bits/stdc++.h>
const int K=20;
int l,r,ans;
inline int F(int a,int k){return((a>>k+1)<<k)+((a&(1<<k+1)-1)>=(1<<k)?(a&(1<<k+1)-1)-(1<<k)+1:0);}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&l,&r);
	ans=r-l;
	for(int k=0;k<K;k++)ans=std::min(ans,(r-l+1)-F(r,k)+F(l-1,k));
	printf("%d\n",ans);
	}return 0;
}