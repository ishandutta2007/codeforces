#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int q,b;ll l,r,ss[11][11][66];
int a[66],top,no;bool now[15];
ll que(ll x){
	top=0;ll ans=0;
	for(;x;x/=b)a[++top]=x%b;
	reverse(a+1,a+top+1);
	//rep(i,top)printf("%d ",a[i]);puts("");
	memset(now,0,sizeof now);no=0;
	rep(i,top){
		for(int j=0;j<a[i];++j){
			if(j==0&&i==1)continue;
			if(now[j])--no;else ++no;now[j]^=1;
			//printf("%d %d %d %lld\n",b,no,top-i,ss[b][no][top-i]);
			ans+=ss[b][no][top-i];
			if(now[j])--no;else ++no;now[j]^=1;
		}
		if(now[a[i]])--no;else ++no;now[a[i]]^=1;
	}
	for(int i=0;i<=top-2;++i)ans+=(b-1)*ss[b][1][i];
	return ans;
}
int main(){
	for(int i=2;i<=10;++i)for(int k=0;k<=64;++k)for(int j=0;j<=i;++j)
			{
				if(k==0){ss[i][j][k]=(j==0);continue;}
				if(j<i)ss[i][j][k]+=1ll*(i-j)*ss[i][j+1][k-1];
				if(j>0)ss[i][j][k]+=1ll*j*ss[i][j-1][k-1];
			}
	//printf("%lld\n",ss[2][1][2]);
	for(scanf("%d",&q);q--;){
		scanf("%d%lld%lld",&b,&l,&r);
		printf("%lld\n",que(r+1)-que(l));
	}
	return 0;
}