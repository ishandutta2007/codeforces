//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,tot,b[N],pri[N],a[N],ax[N],ay[N];
inline void prepare(){
	for(int i=2;i<n;i++){
		if(!b[i])pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<n;j++){
			b[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,x,y);
	int t=y;y=x-a/b*y;x=t;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<4){
		for(int i=1;i<=n;i++)cout<<i<<" "<<i<<"\n"<<-a[i]<<"\n";
		for(int i=n+1;i<=3;i++)cout<<"1 1\n0\n";
		return (0-0);
	}
	prepare();
	m=pri[tot];
	exgcd(n,m,ax[0],ay[0]);
	ax[0]%=m;ay[0]%=n;
	for(int i=1,x;i<=n;i++){
		ax[i]=ax[0];ay[i]=ay[0];
		ax[i]*=-a[i];ay[i]*=-a[i];
		if((ax[i]<0&&ay[i]>0)||(ax[i]>0&&ay[i]<0)){
			x=min(abs(ax[i])/m,abs(ay[i])/n);
			ax[i]+=(ax[i]<0?1:-1)*x*m;
			ay[i]+=(ay[i]<0?1:-1)*x*n;
		}
		ax[i]*=n;ay[i]*=m;
	}
	cout<<"1 "<<n<<"\n";
	for(int i=1;i<=n;i++)cout<<ax[i]<<" ";puts("");
	cout<<"1 "<<m<<"\n";
	for(int i=1;i<=m;i++)cout<<ay[i]<<" ";puts("");
	cout<<n-m+1<<" "<<n<<"\n";
	for(int i=n-m+1;i<=m;i++)cout<<"0 ";
	for(int i=m+1;i<=n;i++)cout<<ay[i]<<" ";puts("");
	return (0-0);
}