#include<bits/stdc++.h>
typedef long long ll;
const int Q=3003,N=2e5+3,M=998244353;
inline int Inv(int a){return a==1?1:(ll)Inv(M%a)*(M-M/a)%M;}
int f[Q],n,m,a[N],c[N],s[2],t[2],inv[Q+Q];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",c+i),c[i]^=1;
	for(int i=1;i<=n;i++)scanf("%d",a+i),s[c[i]]+=a[i];
	for(int i=s[0]+s[1]-m;i<=s[0]+s[1]+m;i++){
		if(i<1)continue;
		inv[i-s[0]-s[1]+m]=Inv(i);
	}
	f[0]=1;
	for(int i=0;i<m;i++)
		for(int j=i,k;~j;j--){
			k=i-j;
			if(!f[j])continue;
			f[j+1]=(f[j+1]+(ll)f[j]*(s[0]+j)%M*inv[m+j-k])%M;
			f[j]=(ll)f[j]*(s[1]-k)%M*inv[m+j-k]%M;
		}
	t[0]=t[1]=1;
	for(int i=0;i<=m;i++){
		if(s[0])t[0]=(t[0]+(ll)f[  i]*i%M*Inv(s[0])%M+M)%M;
		if(s[1])t[1]=(t[1]-(ll)f[m-i]*i%M*Inv(s[1])%M+M)%M;
	}
	for(int i=1;i<=n;i++)printf("%lld\n",(ll)a[i]*t[c[i]]%M);puts("");
	return 0;
}