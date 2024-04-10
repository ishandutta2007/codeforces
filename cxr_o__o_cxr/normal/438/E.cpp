//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
#define R register int
const int mod=998244353,g=3;
inline int zksm(int x,int r){
	int ret=1;
	for(R i=0;(1ll<<i)<=r;i++){
		if((r>>i)&1)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
template<const int mod=::mod>//?
class Z{
	public:
		int v;
		Z():v(0){}
		Z(int x):v(x){}
		Z(ll x):v(x%mod){}
		friend Z operator +(const Z& a,const Z& b){
			static int ret;
			return Z(((ret=a.v+b.v)>=mod)?(ret-mod):(ret));
		}
		friend Z operator -(const Z& a,const Z& b){
			static int ret;
			return Z(((ret=a.v-b.v)<0)?(ret+mod):(ret));
		}
		friend Z operator *(const Z& a,const Z& b){
			return Z((ll)a.v*b.v);
		}	
		friend Z operator ~(const Z& a){
			return Z(zksm(a.v,mod-2));
		}
		friend Z operator -(const Z& a){
			return Z(0)-a;
		}
		Z& operator +=(Z b){
			return *this=*this+b;
		}
		Z& operator -=(Z b){
			return *this=*this -b;
		}
		Z& operator *=(Z b){
			return *this=*this * b;
		}
		friend bool operator ==(const Z& a,const Z& b){
			return a.v==b.v;
		}
};
#define zi Z<>
inline zi ksm(zi x,int r){
	if(r<mod-1)r+=mod-1;//?
	zi ret=1;
	for(R i=0;(1ll<<i)<=r;i++){
		if((r>>i)&1)ret*=x;
		x*=x;
	}
	return ret;
}
const zi inv2(mod+1>>1);
class NTT{
	private:
		zi gn[24],_gn[24];
	public:
		NTT(){
			for(R i=0;i<=20;i++){
				gn[i]=ksm(zi(g),(mod-1)/(1<<i+1));
				_gn[i]=ksm(gn[i],mod-2);
			}
		}
		void operator ()(zi* a,int len,int fl){
			for(R i=1,j=len>>1,k;i<len-1;i++,j+=k){
				if(i<j)swap(a[i],a[j]);
				for(k=len>>1;k<=j;j-=k,k>>=1);
			}
			static zi tmp,x,u,v;
			for(R mid=1,i=0;mid<len;mid<<=1,i++){
				if(fl==1)tmp=gn[i];
				else tmp=_gn[i];
				for(R i=0;i<len;i+=(mid<<1)){
					x=1;
					for(R j=0;j<mid;j++,x*=tmp){
						u=a[i+j];v=x*a[i+j+mid];
						a[i+j]=u+v;a[i+j+mid]=u-v;
					}
				}
			}
			if(fl==-1){
				tmp=~zi(len);
				for(R i=0;i<len;i++)
					a[i]*=tmp;
			}
		}
		inline int corlen(int len){
			int ret=1;
			while(ret<len)ret<<=1;
			return ret;
		}
}NTT;
#define poly vector<zi>
inline void re(poly& a,int x){
	a.resize(x);
}
inline void cre(poly& a,int x){
	a.clear();a.resize(x);
}
inline void co(poly& a,const poly& b,int x){
	for(R i=0;i<x;i++)a[i]=b[i];
}
inline poly operator +(poly a,poly b){
	int mx=max(a.size(),b.size());
	re(a,mx);re(b,mx);
	for(R i=0;i<mx;i++)a[i]+=b[i];
	return a;
}
inline poly operator *(poly a,zi k){
	for(R i=0,sz=a.size();i<sz;i++)a[i]*=k;
	return a;
}
inline poly operator ^(poly a,poly b){
	int mx=max(a.size(),b.size());
	re(a,mx);re(b,mx);
	for(R i=0;i<mx;i++)a[i]*=b[i];
	return a;
}
inline poly operator +(poly a,zi b){
	for(R i=0,sz=a.size();i<sz;i++)a[i]+=b;
	return a;
}
inline poly operator -(poly a,poly b){
	int mx=max(a.size(),b.size());
	re(a,mx);re(b,mx);
	for(R i=0;i<mx;i++)a[i]-=b[i];
	return a;
} 
inline poly operator ~(poly a){
	for(R i=0,sz=a.size();i<sz;i++)a[i]=-a[i];
	return a;
}
inline poly operator *(poly a,poly b){
	static poly c;
	int len=NTT.corlen(a.size()+b.size()+1);
	re(a,len);re(b,len);re(c,len);
	NTT(a.data(),len,1);NTT(b.data(),len,1);
	c=a^b;
	NTT(c.data(),len,-1);
	return c;
}
void getinv(poly a,poly& b,int n){
	if(n==1){b[0]=ksm(a[0],mod-2);return;}
	static poly A;
	int len=NTT.corlen(n<<1);
	getinv(a,b,n+1>>1);
	cre(A,len);re(b,len);co(A,a,n);
	NTT(A.data(),len,1);NTT(b.data(),len,1);
	b=((~(b^A))+2)^b;
	NTT(b.data(),len,-1);
	re(b,n);
} 
inline poly getln(poly a,int n){
	static poly D,I;
	cre(D,n);cre(I,1);
	for(R i=1;i<n;i++)D[i-1]=a[i]*i;
	getinv(a,I,n);
	D=D*I;
	for(R i=1;i<n;i++)I[i]=D[i-1]*(~zi(i));
	I[0]=0;
	re(I,n);
	return I; 
}
void getexp(poly a,poly& b,int n){
	if(n==1){b[0]=1;return;}
	static poly c,A;
	int len=NTT.corlen(n<<1);
	getexp(a,b,n+1>>1);
	re(b,n);
	c=getln(b,n);
	cre(A,len);co(A,a,n);re(b,len);re(c,len);
	NTT(A.data(),len,1);NTT(b.data(),len,1);NTT(c.data(),len,1);
	b=b^(A-c+1);
	NTT(b.data(),len,-1);
	re(b,n);
}
inline poly ksm(poly a,int n,int r){
	static poly I,b;
	I=getln(a,n);
	I=I*r;
	cre(b,1);
	getexp(I,b,n);
	return b;
}
void getsqr(poly a,poly& b,int n){
	if(n==1){b[0]=1;return;}
	static poly I,A;
	int len=NTT.corlen(n<<1);
	getsqr(a,b,n+1>>1);
	cre(I,1);re(b,len); 
	getinv(b,I,n);
	re(I,len);cre(A,len);co(A,a,n);
	NTT(A.data(),len,1);NTT(b.data(),len,1);NTT(I.data(),len,1);
	b=((I^A)+b)*inv2;
	NTT(b.data(),len,-1);
	re(b,n);
}
poly a,c;
int main(){
	int n=read(),m=read()+1;
	re(c,m);re(a,1);
	for(int i=1,x;i<=n;i++){
		x=read();
		if(x>=m)continue;
		c[x]=mod-4;
	}
	c[0]=1;
	getsqr(c,a,m);
	a[0].v++;
	a=a*inv2;
	cre(c,1);
	getinv(a,c,m);
	for(int i=1;i<m;i++)cout<<c[i].v<<"\n";
	return (0-0);
}