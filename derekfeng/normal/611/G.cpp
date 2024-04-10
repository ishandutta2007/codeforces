#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int M=1e9+7;
struct Vec{ll x,y;}a[500005],pre[500005];
Vec operator +(Vec a,Vec b){return (Vec){a.x+b.x,a.y+b.y};}
Vec operator -(Vec a,Vec b){return (Vec){a.x-b.x,a.y-b.y};}
ll operator *(Vec a,Vec b){return a.y*b.x-a.x*b.y;}
int n;ll S,p[500005],s[500005],ans;
int main(){
	scanf("%d",&n);pre[0]={0,0};
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y,pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
		p[i]=p[i-1]+a[i-1]*a[i],s[i]=(s[i-1]+p[i])%M;
	S=p[n]+a[n]*a[1];
	for(int i=1,it=2;i<=n-2;i++){
		while(it<i+1)it++;
		while(it<n&&p[it+1]-p[i]+a[it+1]*a[i]<=S/2)it++;
		if(i+2<=it){
			int tot=it-i-1;
			ll h=((s[it]-s[i+1])%M-p[i]%M*tot%M+(pre[it]-pre[i+1])*a[i]%M)%M;
			(ans+=S%M*tot-h*2)%=M;
		}
		int m=min(n,i+n-2);
		if(it<m){
			int tot=m-it;
			ll h=((s[m]-s[it])%M-p[i]%M*tot%M+(pre[m]-pre[it])*a[i]%M)%M;
			(ans+=h*2-S%M*tot)%=M;
		}
	}
	ans=(ans+M)%M;
	long long res=ans;
	printf("%lld",res);
}