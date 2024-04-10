#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MX=200005;
int n,m,q;
int w[MX];

typedef pair<int,int> pii;
#define fr first
#define se second
#define mp make_pair
inline pii pw(int x,int y,int md){//(x^y mod md,x^y >= md)
	int r=1,fx=0,fr=0;
	while(y){
		if(y&1)fr|=fx,fr|=(int)((LL)r*x>=md),r=(LL)r*x%md;
		fx|=(int)((LL)x*x>=md),x=(LL)x*x%md;y>>=1;
	}
	return mp(r,fr);
}
int phi(int x){
	int ans=1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)ans*=i-1,x/=i;
		while(x%i==0){
			ans*=i;x/=i;
		}
	}
	if(x>1)ans*=x-1;
	return ans;
}
int md[MX],mdc=1;
void ini(){
	md[1]=m;
	while(md[mdc]>1)md[mdc+1]=phi(md[mdc]),mdc++;
}
pii que(int l,int r,int mdi){//first :al^al+1^...^ar mod md[mdi] second :min(1,al^al+1^...^ar>=md[mdi])
	if(l==r){
		return mp(w[l]%md[mdi],(int)(w[l]>=md[mdi]));
	}
	if(md[mdi]==1)return mp(0,1);
	pii res=que(l+1,r,mdi+1);
	int p=res.fr+res.se*md[mdi+1];
	return pw(w[l],p,md[mdi]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	ini();
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		cout<<que(l,r,1).fr<<endl;
	}
	return 0;
}