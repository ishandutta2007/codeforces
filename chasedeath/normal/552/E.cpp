#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>
#include<cstring>
#include<map>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=5011,INF=1e9+10;


int n;
char s[N];
struct Node{
	int opt;
	ll x;
}a[N],b[N];




ll Solve(Node *s,int l,int r){
	ll t=s[l].x,res=0;
	rep(i,l+1,r) {
		if(s[i].opt==1) t*=s[i].x;
		else res+=t,t=s[i].x;
	}
	return res+t;
}








int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i+=2) a[i/2+1].opt=(s[i-1]!='+'),a[i/2+1].x=s[i]-'0';
	n=n/2+1;
	ll ans=Solve(a,1,n);
	//cout<<ans<<endl;
	rep(i,1,n) if(a[i].opt) rep(j,i+1,n+1) if(a[j].opt||j==n+1) {
		ll t=Solve(a,i,j-1);
		int c=0;
		rep(k,1,i-1) b[++c]=a[k];
		b[++c]=(Node){1,t};
		rep(k,j,n) b[++c]=a[k];
		ans=max(ans,Solve(b,1,c));
		//cout<<i<<' '<<j<<' '<<t<<' '<<Solve(b,1,c)<<endl;
	}
	printf("%lld\n",ans);
}