#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2000020,mo=1e9+7;
int n,a[N],prime[N],len,mrk[N],c[N];Pii b[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];if(i%prime[j]==0)break;
		}
	}
}
vector<Pii>solve(int x){
	vector<Pii>res;
	while(mrk[x]){
		int c=0,v=mrk[x];while(x%v==0)x/=v,c++;res.push_back(Pii(v,c));
	}
	if(x>1)res.push_back(Pii(x,1));
	return res;
}
int main(){
	getp(2000000);scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);bool ok=0;
	per(i,n,1)
	if(!b[a[i]].fi)b[a[i]]=Pii(1,1),c[i]=a[i];
	else{
		vector<Pii>f=solve(a[i]-1);per(i,SZ(f)-1,0){
			int x=f[i].fi,y=f[i].se;
			if(y>b[x].fi)b[x]=Pii(y,1);else if(y==b[x].fi)b[x].se++;
		}
		c[i]=a[i]-1;
	}
	rep(i,1,n){
		vector<Pii>f=solve(c[i]);bool bo=1;
		per(i,SZ(f)-1,0){
			int x=f[i].fi,y=f[i].se;
			bo&=!(y==b[x].fi&&b[x].se==1);
		}
		ok|=bo;
	}
	int res=1;rep(i,1,2000000)per(j,b[i].fi,1)res=1LL*res*i%mo;if(ok)res=(res+1)%mo;
	cout<<res;
	return 0;
}