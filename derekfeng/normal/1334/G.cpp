#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353,Gg=3,Gi=332748118;
int A[524288],B[524288],C[524288],rev[524288],N=1,lg;
int myp(int x,int t){int a=1;for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;return a;}
int ag[1048576],ai[1048576];
int *wg[24],*wi[24];
void ntt(int *A,int z){
	for(int i=0;i<N;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int t=2,c=0;t<=N;t<<=1,c++){
		int md=t>>1;
		for(int j=0;j<N;j+=t){
			int *it=z==1?wg[c]:wi[c];
			for(int k=0;k<md;k++){
				int x=A[j+k],y=(ll)A[j+md+k]*(*it++)%M;
				A[j+k]=(x+y<M?x+y:x+y-M),A[j+md+k]=(x-y<0?x-y+M:x-y);
			}
		}
	}if(z<0){int iv=myp(N,M-2);for(int i=0;i<N;i++)A[i]=(ll)A[i]*iv%M;}
}
int n,m,p[26];bool ok[200004];
char s[200004],t[200004];
int a[200004],b[200004],v[200004];
mt19937 rng(1919810);
int main(){
	for(int i=0;i<26;i++)scanf("%d",&p[i]),p[i]--;
	scanf("%s%s",s,t),n=strlen(s),m=strlen(t),reverse(s,s+n);
	for(int i=0;i<n;i++)a[i]=s[i]-'a';
	for(int i=0;i<m;i++)b[i]=t[i]-'a';
	while(N<=n+m-2)N<<=1,lg++;
	for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	int *it1=ag,*it2=ai;for(int i=0;i<lg;i++){
		int wG=myp(Gg,(M-1)/(1<<(i+1)));
		int wI=myp(Gi,(M-1)/(1<<(i+1)));
		wg[i]=it1,wi[i]=it2;
		*it1=1,*it2=1,it1++,it2++;
		int pg=1,pi=1;
		for(int j=1;j<(1<<i);j++){
			pg=(ll)pg*wG%M,pi=(ll)pi*wI%M;
			*it1=pg,it1++,*it2=pi,it2++;
		}
	}
	for(int i=0;i<26;i++)v[i]=rng()%M;
	for(int x=0;x<3;x++)for(int y=0;y<3;y++){
		memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
		for(int i=0;i<n;i++){
			A[i]=1;
			if(x==0)A[i]=(ll)v[a[i]]*v[a[i]]%M;
			if(x==1)A[i]=M-2*v[a[i]]%M;
			if(y==0)A[i]=(ll)A[i]*v[p[a[i]]]%M*v[p[a[i]]]%M;
			if(y==1)A[i]=(ll)A[i]*(M-2*v[p[a[i]]]%M)%M;
		}
		for(int i=0;i<m;i++){
			B[i]=1;
			if(x==1)B[i]=v[b[i]];
			if(x==2)B[i]=(ll)v[b[i]]*v[b[i]]%M;
			if(y==1)B[i]=(ll)B[i]*v[b[i]]%M;
			if(y==2)B[i]=(ll)B[i]*v[b[i]]%M*v[b[i]]%M;
		}
		ntt(A,1),ntt(B,1);
		for(int i=0;i<N;i++)(C[i]+=(ll)A[i]*B[i]%M)%=M;
	}
	ntt(C,-1);
	for(int i=0;i<=m-n;i++)putchar(C[i+n-1]?'0':'1');
}