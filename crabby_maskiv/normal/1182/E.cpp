#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1e9+7;
int n,m;
struct mat{
	int n,m;
	ll x[6][6];
};
mat mul(const mat &a,const mat &b){
	mat ret;
	ret.n=a.n;ret.m=b.m;
	int i,j,k;
	memset(ret.x,0,sizeof(ret.x));
	for(i=1;i<=ret.n;i++){
		for(j=1;j<=ret.m;j++){
			for(k=1;k<=a.m;k++){
				ret.x[i][j]+=a.x[i][k]*b.x[k][j];
				ret.x[i][j]%=mod-1;
			}
		}
	}
	return ret;
}
mat po(const mat &base,ll k){
	if(k==1) return base;
	mat s=po(base,k>>1);
	s=mul(s,s);
	if(k&1) return mul(s,base);
	else return s;
}
ll po2(const ll &p,ll k){
	if(k==0) return 1;
	ll s=po2(p,k>>1);
	s=s*s%mod;
	if(k&1) return s*p%mod;
	else return s;
}
mat base;
ll k,f1,f2,f3,c;
int main(){
    int i,j;
	mat b1,b2,a;
	ll p1,p2,p3,pc;
	cin>>k>>f1>>f2>>f3>>c;
	memset(b1.x,0,sizeof(b1.x));
	memset(b2.x,0,sizeof(b2.x));
	memset(a.x,0,sizeof(a.x));
	b1.n=b1.m=3;
	b1.x[1][1]=b1.x[1][2]=b1.x[1][3]=b1.x[2][1]=b1.x[3][2]=1;
	b2.n=b2.m=5;
	b2.x[1][1]=b2.x[1][2]=b2.x[1][3]=b2.x[1][4]=b2.x[2][1]=b2.x[3][2]=b2.x[4][4]=b2.x[4][5]=b2.x[5][5]=1;
	b1=po(b1,k-3);
	b2=po(b2,k-3);
	a.n=3;a.m=1;a.x[1][1]=1;a.x[2][1]=a.x[3][1]=0;
	p3=mul(b1,a).x[1][1];
	a.n=3;a.m=1;a.x[2][1]=1;a.x[1][1]=a.x[3][1]=0;
	p2=mul(b1,a).x[1][1];
	a.n=3;a.m=1;a.x[3][1]=1;a.x[2][1]=a.x[1][1]=0;
	p1=mul(b1,a).x[1][1];
	a.n=5;a.m=1;a.x[1][1]=a.x[2][1]=a.x[3][1]=0;a.x[4][1]=a.x[5][1]=2;
	pc=mul(b2,a).x[1][1];
	ll ans=po2(f1,p1)*po2(f2,p2)%mod;
	ans*=(po2(f3,p3)*po2(c,pc)%mod);
	ans%=mod;
	cout<<ans;
    return 0;
}
// 1 1 1
// 1 0 0
// 0 1 0 

// 1 1 1 1 0
// 1 0 0 0 0
// 0 1 0 0 0
// 0 0 0 1 1
// 0 0 0 0 1