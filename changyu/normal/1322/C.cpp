#include<bits/stdc++.h>
#define int unsigned long long 
int Gcd(int a,int b){return b?Gcd(b,a%b):a;}
const int N=5e5+3;
int n,m,a[N],s,ans;
struct hash{int h1,h2,h3,a;}h[N];
bool Cmp(const hash&a,const hash&b){
	if(a.h1==b.h1){
	  if(a.h2==b.h2)
		return a.h3<b.h3;
	  return a.h2<b.h2;
	}return a.h1<b.h1;
}
signed main(){
	int u,v;
	int T;scanf("%llu",&T);for(;T--;){
	scanf("%llu%llu",&n,&m);
	for(int i=1;i<=n;i++)scanf("%llu",&h[i].a),h[i].h1=h[i].h2=h[i].h3=0;
	for(;m--;){
	  scanf("%llu%llu",&u,&v);
	  h[v].h1^=u;
	  h[v].h2*=u^n+1;
	  h[v].h3+=u*u*u;
	}
	std::sort(h+1,h+1+n,Cmp);
	ans=0,s=0;
	for(int i=1;i<=n;i++){
	  if(!h[i].h1&&!h[i].h2&&!h[i].h3)continue;
	  if(h[i].h1==h[i-1].h1&&h[i-1].h2==h[i].h2&&h[i-1].h3==h[i].h3)
		s+=h[i].a;
	  else{
		ans=Gcd(ans,s);
		s=h[i].a;
	  }
	}
	ans=Gcd(ans,s);
	printf("%llu\n",ans);
	}return 0;
}