#include<cstdio>
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
int t,n,k,m9,sz,x,st;char ans[400],tmp[400];
inline bool chk()
{if(ans[0]=='-') return true;if(st<sz) return 1;if(st>sz) return 0;for(int i=st-1,j=0;i+1;--i,++j) if(tmp[i]^ans[j]) return tmp[i]<ans[j];return 0;}
inline void update(){if(!chk()) return;sz=st;for(int i=0;i<sz;++i) ans[sz-i-1]=tmp[i];}
int main(){
	read(t);while(t--){
		read(n);read(k);ans[0]='-';ans[1]='1';sz=2;m9=n/9+1;
		for(int i=0;i<=9&&i<=n;++i,m9=((n-i)/9)+1)
			for(int j=0;j<=m9;++j){
				if(((i+k)>9&&!j)||(i+k<10&&j)) continue;
				x=2*(n+9*j*(i+k-9));
				if(x%(k+1)) continue;
				x=x/(k+1)-k-2*i-18*(j-1);if(!j) x-=18;
				if(x<0||x&1) continue;
				x>>=1;
				tmp[st=0]=i+48;for(int o=1;o<j;++o) tmp[++st]=57;if(j&&x>7) tmp[++st]=56,x-=8;
				for(;x>8;x-=9) tmp[++st]=57;if(x) tmp[++st]=x+48;++st;update();
			}
		for(int i=0;i<sz;++i) putchar(ans[i]);putchar('\n');
	}
	return 0;
}