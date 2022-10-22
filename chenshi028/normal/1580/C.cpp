#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
const int o=5e5+10,B=400;
int n,m,x[o],y[o],op[o],st[o],pos[o],b[o],a[B+10][B+10];
inline void chg(int s,int f,int val){
	int t=x[f]+y[f];s%=t;
	for(int i=(s+x[f])%t;1;){
		a[t][i]+=val;
		if(++i==t) i=0;
		if(i==s) break;
	}
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) read(x[i]),read(y[i]);
	for(int i=1;i<=m;++i){
		read(op[i]);read(pos[i]);
		if(x[pos[i]]+y[pos[i]]>B) if(op[i]==1) st[pos[i]]=i;
		else{
			for(int j=st[pos[i]],k=x[pos[i]],$=x[pos[i]]+y[pos[i]];j<i;j+=$) ++b[Min(j+k,i)],--b[Min(j+$,i)];
			st[pos[i]]=0;
		}
	} 
	for(int i=1;i<=n;++i) if(st[i])
		for(int j=st[i],k=x[i],$=x[i]+y[i];j<=m;j+=$) ++b[Min(j+k,m+1)],--b[Min(j+$,m+1)];
	for(int i=1;i<=m;++i) b[i]+=b[i-1];
	for(int i=1;i<=m;printf("%d\n",b[i++])){
		if(x[pos[i]]+y[pos[i]]<=B) if(op[i]==1) chg(st[pos[i]]=i,pos[i],1);else chg(st[pos[i]],pos[i],-1);
		for(int j=2;j<=B;++j) b[i]+=a[j][i%j];
	}
	return 0;
}