#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=1e5+4,g=3,mod=998244353; 
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if((1<<i)&r)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
int n,a,b,rev[N<<2];
#define vec vector<int>
vec ans;
inline void ntt(int *a,int fl,int lim,int len){
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<lim-1);
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int mid=1,tmp,x,u,v;mid<len;mid<<=1){
		tmp=ksm(g,(mod-1)/(mid<<1));
		if(fl==-1)tmp=ksm(tmp,mod-2);
		for(int i=0;i<len;i+=(mid<<1)){
			x=1;
			for(int j=0;j<mid;j++,x=(ll)x*tmp%mod){
				u=a[i+j];v=(ll)a[i+j+mid]*x%mod;
				a[i+j]=(u+v)%mod;a[i+j+mid]=(u-v+mod)%mod; 
			}
		}
	}
	if(fl==-1)for(int i=0,tmp=ksm(len,mod-2);i<len;i++)
		a[i]=(ll)a[i]*tmp%mod;
}
vec mul(vec &A,vec &B){
	static vec C;
	int lim=0,len=1;
	while(len<A.size()+B.size()-1){len<<=1;lim++;}
	A.resize(len);B.resize(len);C.clear();C.resize(len);
	ntt(&A[0],1,lim,len);ntt(&B[0],1,lim,len);
	for(int i=0;i<len;i++)C[i]=(ll)A[i]*B[i]%mod;
	ntt(&C[0],-1,lim,len);
	return C;
}
vec solve(int l,int r){
	vec L,R;
	if(l==r)return {l,1};
	int mid=l+r>>1;
	L=solve(l,mid);R=solve(mid+1,r);
	return mul(L,R);
}
inline int fac(int x){
	int ret=1;
	for(int i=1;i<=x;i++)ret=(ll)ret*i%mod;
	return ret;
}
inline int C(int n,int m){
	return (ll)fac(n)*ksm(fac(m),mod-2)%mod*ksm(fac(n-m),mod-2)%mod; 
}
int main(){
	n=read();a=read();b=read();
	if(n==1&&a==1&&b==1){puts("1");return (0-0);}
	if(n==1||a==0||b==0||a+b-2>=n){puts("0");return (0-0);} 
	ans=solve(0,n-2);
	cout<<(ll)ans[a+b-2]*C(a+b-2,a-1)%mod;
	return (0-0);
}