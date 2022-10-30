#include<bits/stdc++.h>
#define int long long
const int N=5000005;
const int mod=1e9+7;
using namespace std;

int n,m,s1,s2,ty,ans[N],t[N],a[N];

signed p[N],k[N],b[N],w[N],res=1;
int seed,base;
int rnd() {
	int res=seed;
	seed=(seed*base+233)%mod;
	return res;
}
void generate() {
	p[0]=0;
	for(int i=1;i<=m;i++){
		seed=b[i],base=w[i];
		for(int j=p[i-1]+1;j<=p[i];j++){
			t[j]=(rnd()%2)+1;
			a[j]=(rnd()%k[i])+1;
		}
	}
}


main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>p[i]>>k[i]>>b[i]>>w[i];
	generate();
	for(int i=1;i<=n;i++)
		if(t[i]==1)s1+=a[i];
		else s2+=a[i];
	if(s1<s2)ty=1;
	else ty=2;
	int nw=1;
	for(int i=1,s=t[1]!=ty,d;i<=n<<1;i++){
		if(t[nw]==ty)s+=a[nw],ans[nw]+=a[nw],a[nw]=0;
		else {
			d=min(a[nw],s);
			if(d&&i>n)
				i--;
			ans[nw]+=d,s-=d,a[nw]-=d;
		}
		nw=nw%n+1;
	}
	for(int i=1;i<=n;i++)
		res=res*(((ans[i]^(i*i))+1)%mod)%mod;
	cout<<res;
}