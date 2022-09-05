#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=a;i<=b;i++)
const int N = 2030;
int a,b,c,prime[N],len,mrk[N],mu[N];long long res;bool gg[N][N];
void getp(int n){
	mu[1]=1;rep(i,2,n){//WA
		if(!mrk[i])prime[++len]=i,mu[i]=-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;mu[i*prime[j]]=-mu[i];
		}
	}
	rep(i,1,len)for(int a=prime[i];a<=n;a+=prime[i])
		for(int b=prime[i];b<=n;b+=prime[i])gg[a][b]=1;
}
inline int solve(int a, int d, int k){
	int res=0,mx=a/d;
	rep(i,1,mx)res+=!gg[k][d*i]?a/(d*i):0;
	return res;
}
int main(){
	scanf("%d%d%d",&a,&b,&c);getp(2000);
	rep(d,1,min(a,b))if(mu[d])rep(k,1,c)res+=1LL*mu[d]*(c/k)*solve(a,d,k)*solve(b,d,k);
	cout<<(res&((1<<30)-1));return 0;
}