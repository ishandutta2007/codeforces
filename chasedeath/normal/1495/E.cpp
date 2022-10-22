#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=5e6+10,P=1e9+7;

int n;
int seed,base;
int rnd(){
	int ret=seed;
	seed=(1ll*seed*base+233)%P;
	return ret;
}

int A[N],T[N],L[N],R[N];
ll S[2];
int B[N];
int nxt[N];

int main(){
	n=rd();
	for(int _=rd(),lst=0;_--;){
		int p=rd(),k=rd();
		seed=rd(),base=rd();
		rep(i,lst+1,p) T[i]=rnd()%2,S[T[i]]+=A[i]=rnd()%k+1;
		lst=p;
	}
	int L=1;
	if(S[T[1]]>S[!T[1]]) {
		S[T[1]]--,A[1]--,B[1]++;
		while(L<=n && T[L]==T[1]) L++;
	}
	int p=L; ll c=0;
	if(L>n) goto End;
	while(S[T[L]]) {
		if(T[p]==T[L]) {
			B[p]+=A[p];
			c+=A[p];
			A[p]=0;
		} else {
			ll w=min(c,(ll)A[p]);
			c-=w,A[p]-=w,B[p]+=w,S[T[L]]-=w;
		}
		p=p%n+1;
	}
	End:;
	int ans=1;
	rep(i,1,n) ans=(((1ll*i*i)^B[i])+1)%P*ans%P;
	printf("%d\n",ans);
}