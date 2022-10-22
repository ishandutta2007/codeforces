#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline void mx(long long&a,long long b){if(a<b) a=b;}
const int o=4010;
int n,m,a[o],s[o],st[o],l[o],r[o],tp,rt;long long f[o][o],lst[o];
void dfs(int nw){
	long long w1=a[l[nw]]-a[nw],w2=a[r[nw]]-a[nw];
	if(l[nw]) lst[l[nw]]=w1,dfs(l[nw]);
	if(r[nw]) lst[r[nw]]=w2,dfs(r[nw]);
	for(int i=0;i<=s[l[nw]];++i) for(int j=0;j<=s[r[nw]];++j)
		mx(f[nw][i+j],f[l[nw]][i]+f[r[nw]][j]),mx(f[nw][i+j+1],f[l[nw]][i]+f[r[nw]][j]);
	s[nw]=s[l[nw]]+s[r[nw]]+1;
	for(int i=0;i<=s[nw];++i) f[nw][i]+=lst[nw]*i*(m-i);
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i){
		for(read(a[i]);tp&&a[st[tp]]>=a[i];--tp);
		if(!tp) l[i]=rt,rt=i;
		l[i]=r[st[tp]];r[st[tp]]=i;st[++tp]=i;
	}
	dfs(rt);
	printf("%lld",f[rt][m]);
	return 0;
}