#include<cstdio>
#include<iostream>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=1e6+10;
int n,m,ans,f[o][4];string s[o];
inline int g(int ind,int st)
{return min((s[1][ind]^(st&1)^(!s[2][ind]))+(s[3][ind]^(st>>1)^(!s[2][ind]))+1,(s[1][ind]^(st&1)^s[2][ind])+(s[3][ind]^(st>>1)^s[2][ind]));}
inline int h(int ind,int st)
{return min((s[ind][0]^(st&1)^(!s[ind][1]))+(s[ind][2]^(st>>1)^(!s[ind][1]))+1,(s[ind][0]^(st&1)^s[ind][1])+(s[ind][2]^(st>>1)^s[ind][1]));}
int main(){
	read(n);read(m);if(n>3&&m>3){printf("-1");return 0;}if(n<2||m<2){printf("0");return 0;}for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) for(int j=0;j<m;++j) s[i][j]-=48;
	if(n==2){for(int i=0;i<m;++i) ans+=(s[1][i]^s[2][i]^(i&1));write(min(ans,m-ans));return 0;}
	if(n==3){
		for(int i=0;i<4;++i) f[0][i]=g(0,i);for(int i=1;i<m;++i) for(int j=0;j<4;++j) f[i][j]=f[i-1][3-j]+g(i,j);
		write(min(min(f[m-1][0],f[m-1][1]),min(f[m-1][2],f[m-1][3])));
		return 0;
	}
	if(m==2){for(int i=1;i<=n;++i) ans+=(s[i][0]^s[i][1]^(i&1));write(min(ans,n-ans));return 0;}
	for(int i=1;i<=n;++i) for(int j=0;j<4;++j) f[i][j]=f[i-1][3-j]+h(i,j);
	write(min(min(f[n][0],f[n][1]),min(f[n][2],f[n][3])));
	return 0;
}