// Problem: CF1103E Radix sum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1103E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef unsigned long long ull;
ull inv5=14757395258967641293ull;
struct cp{
	ull a[4];
	cp(ull a0=0,ull a1=0,ull a2=0,ull a3=0){a[0]=a0,a[1]=a1,a[2]=a2,a[3]=a3;}
	cp operator+(cp rhs){return cp(a[0]+rhs.a[0],a[1]+rhs.a[1],a[2]+rhs.a[2],a[3]+rhs.a[3]);}
	cp operator-(cp rhs){return cp(a[0]-rhs.a[0],a[1]-rhs.a[1],a[2]-rhs.a[2],a[3]-rhs.a[3]);}
	cp operator*(cp rhs){
		static ull arr[5];memset(arr,0,sizeof arr);
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)
			if(i+j<5)arr[i+j]+=a[i]*rhs.a[j];
			else arr[i+j-5]-=a[i]*rhs.a[j];
		return cp(arr[0]-arr[4],arr[1]+arr[4],arr[2]-arr[4],arr[3]+arr[4]);
	}
	friend cp operator^(cp a,int b){
		cp res(1,0,0,0);
		while(b){
			if(b&1)res=res*a;
			a=a*a;b>>=1;
		}
		return res;
	}
	void print(){for(int i=0;i<4;i++)write(a[i]),pc(' ');pc('\n');}
};
cp w[10],iw[10];
const int N=1e5;
array<cp,10>dft(array<cp,10>&f,int op){
	array<cp,10>g;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)
		g[i]=g[i]+f[j]*(op>0?w:iw)[i*j%10];
	return g;
}
void fwt(cp*f,int op){
	for(int i=1;i<N;i*=10)
		for(int j=0;j<N;j+=i*10)
			for(int k=0;k<i;k++){
				array<cp,10>arr;
				for(int l=0;l<10;l++)arr[l]=f[j+k+l*i];
				arr=dft(arr,op);
				for(int l=0;l<10;l++)f[j+k+l*i]=arr[l];
			}
}
int n;
cp f[N];

signed main(){
	w[0]=cp(1,0,0,0);w[1]=cp(0,1,0,0);
	for(int i=2;i<10;i++)w[i]=w[i-1]*w[1];
	iw[0]=cp(1,0,0,0);iw[1]=w[9];
	for(int i=2;i<10;i++)iw[i]=iw[i-1]*iw[1];
	read(n);
	for(int i=1,x;i<=n;i++)read(x),f[x].a[0]+=1;
	fwt(f,1);
	for(int i=0;i<N;i++)f[i]=f[i]^n;
	fwt(f,-1);
	for(int i=0;i<n;i++)writeln((f[i].a[0]*inv5*inv5*inv5*inv5*inv5>>5)%(1ull<<58));
}