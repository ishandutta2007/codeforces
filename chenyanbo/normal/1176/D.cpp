#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int f[3000005];
int a,t,n,ss,A[240005],o[3000005];
multiset<int>S;
int main()
{
	for(int i=2;i<=2750131;++i){
		for(int j=i<<1;j<=2750131;j+=i){
			f[j]=i;
		}
	}
	for(int i=2;i<=2750131;++i)if(!f[i])o[i]=++ss;
	n=read()*2;
	for(int i=1;i<=n;++i)S.insert(read());
	while(!S.empty()){
		t=*(--S.end());
		if(f[t]){
			A[++a]=t;
			S.erase(--S.end());
			S.erase(S.lower_bound(f[t]));
		}else{
			A[++a]=o[t];
			S.erase(--S.end());
			S.erase(S.lower_bound(o[t]));
		}
	}
	n=n>>1; // 16 32 64 // m //??
	for(int i=1;i<=n;++i)printf("%d ",A[i]);
}