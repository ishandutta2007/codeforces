#include<bits/stdc++.h>
typedef long long ll;
const int N=3e5+3,M[2]={998244353,1004535809},B[2]={3,3},INVB[2]={332748118,334845270};
int n,a[N],b[N],bt[N],f[N],PW[N],INVPW[N];
inline void Add(int k,int a,bool o){for(;k&&k<=n;k+=k&-k)bt[k]=(bt[k]+a)%M[o];}
inline int Sum(int k,bool o){int s=0;for(;k;k-=k&-k)s=(s+bt[k])%M[o];return s;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]=i;
	for(int o=0;o<2;o++){
		PW[0]=INVPW[0]=1;
		for(int i=1;i<=n;i++)PW[i]=(ll)PW[i-1]*B[o]%M[o],INVPW[i]=(ll)INVPW[i-1]*INVB[o]%M[o];
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=1;i<=n;i++)bt[i]=0;
		for(int i=1,j;i<=n;i++){
			f[i]=(f[i]+(ll)Sum(b[i],o)*PW[i])%M[o];
			Add(b[i],INVPW[i],o);
			if(n-i&1){
				j=i+(n-i+1)/2;
				f[j]=(f[j]-(ll)Sum(b[j],o)*PW[j])%M[o];
			}
		}
		for(int i=1;i<=n;i++)bt[i]=0;
		for(int i=n,j;i;i--){
			f[i]=(f[i]-(ll)Sum(b[i],o)*INVPW[i])%M[o];
			Add(b[i],PW[i],o);
			if(~i&1){
				j=i/2;
				f[j]=(f[j]+(ll)Sum(b[j],o)*INVPW[j])%M[o];
			}
		}
		for(int i=1;i<=n;i++)if(f[i]){puts("YES");goto Brk;}
	}
	puts("NO");
	Brk:;
	return 0;
}