#include<cstdio>
using namespace std;
const int o=4e4+10,MOD=1e9+7;
inline int fix(int x){return x+(x>>31&MOD);}
int T,n,f[o];
inline int calc(int x,int p){
	for(;p--;x/=10);
	return x%10;
}
inline bool chk(int x){
	if(x<10) return true;
	if(x<100) return calc(x,0)==calc(x,1);
	if(x<1000) return calc(x,0)==calc(x,2);
	if(x<10000) return calc(x,0)==calc(x,3)&&calc(x,1)==calc(x,2);
	return calc(x,0)==calc(x,4)&&calc(x,1)==calc(x,3);
}
int main(){
	for(int i=f[0]=1;i<o;++i) if(chk(i)) for(int j=i;j<o;++j) f[j]=fix(f[j]+f[j-i]-MOD);
	for(scanf("%d",&T);T--;printf("%d\n",f[n])) scanf("%d",&n);
	return 0;
}