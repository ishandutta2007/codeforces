#include<bits/stdc++.h>
#define mp make_pair
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
const int N=1e3+100;
int n,x[N],y[N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(x[i],y[i]);
	while(1){
		int cnt=0;
		for(int i=1;i<=n;i++)if((x[i]+y[i])%2==0)cnt++;
		if(0<cnt&&cnt<n){
			write(cnt);pc('\n');
			for(int i=1;i<=n;i++)if((x[i]+y[i])%2==0)
				write(i),pc(' ');
			return 0;
		}
		if(cnt==0)for(int i=1;i<=n;i++)x[i]--;
		for(int i=1;i<=n;i++){
			int xx=(x[i]+y[i])/2,yy=(x[i]-y[i])/2;
			x[i]=xx,y[i]=yy;
		}
	}
}