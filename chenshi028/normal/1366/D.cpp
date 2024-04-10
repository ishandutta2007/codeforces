//my own editorial:p refers to a prime. Pick all primes smaller than 1e7 first. If a=p^k, the answer is "-1 -1"
//If a=(p^k)*m (where p is the smallest divisor of a and (p,m)=1), the answer is "p m". Obviously it's correct.
//Proof:
//If a=p^k, p|d1+d2 and p|a, so p|gcd(d1+d2,a).
//If a=(p^k)*m and gcd(p+m,a)=q (q>1), q|p+m and q|a.
//	If p|q, q|p+m => p|p+m => p|m. It's impossible.
//  If (p,q)=1, q|a => q|m =>q|p. It's impossible.
//QED.
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
const int o=1e7+10;
int n,a,cnt,p[o],s1[o],s2[o];bool vis[o];
inline void linear_sift(){
	for(int i=2;i<o;++i){
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&i*1ll*p[j]<o;++j){vis[i*p[j]]=1;if(i%p[j]==0) break;}
	}
}
int main(){
	linear_sift();read(n);
	for(int i=1;i<=n;++i){
		read(a);
		for(int j=1;j<=cnt&&p[j]*p[j]<=a;++j) if(a%p[j]==0){s1[i]=p[j];while(a%p[j]==0) a/=p[j];break;}
		if(a==1||!s1[i]) s1[i]=-1,s2[i]=-1;else s2[i]=a;
	}
	for(int i=1;i<=n;++i) write(s1[i]),putchar(' ');
	putchar('\n');for(int i=1;i<=n;++i) write(s2[i]),putchar(' ');
	return 0;
}