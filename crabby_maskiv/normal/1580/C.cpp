#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;

const int N=2e5+5;
const int M=sqrt(N)+5;
int n,m;
int w[M][M];
int pos[N];
int x[N],y[N];
int cur;
int d[N];
int main(){
	int i,j;
	qio>>n>>m;
	for(i=1;i<=n;i++) qio>>x[i]>>y[i];
	int B=sqrt(m);
	int op,id,c;
	for(i=1;i<=m;i++){
		cur+=d[i];
		qio>>op>>id;
		c=x[id]+y[id];
		if(op==1){
			pos[id]=i;
			if(c<=B){
				int t=(i+x[id])%c;
				for(j=x[id]+1;j<=c;j++,t=((t==c-1)?0:(t+1)))
					w[c][t]++;
			}
			else{
				for(j=i;j+x[id]<=m;j+=c){
					d[j+x[id]]++;
					if(j+c<=m) d[j+c]--;
				}
			}
		}
		else{
			if(c<=B){
				int t=(pos[id]+x[id])%c;
				for(j=x[id]+1;j<=c;j++,t=((t==c-1)?0:(t+1)))
					w[c][t]--;
			}
			else{
				for(j=pos[id];j+x[id]<=m;j+=c){
					d[j+x[id]]--;
					if(j+x[id]<=i) cur--;
					if(j+c<=m) d[j+c]++;
					if(j+c<=i) cur++;
				}
			}
		}
		int ans=cur;
		for(j=2;j<=B;j++)
			ans+=w[j][i%j];
		qio<<ans<<'\n';
	}
	return 0;
}