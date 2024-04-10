#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=110;

ll m;
int k;
int a[N],c;
ll dp[100][100];

ll dfs(int p,int c,int lim){
	if(p==0) return c==k;
	if(!lim&&~dp[p][c]) return dp[p][c];
	int up=lim?a[p]:1;
	ll res=0;
	rep(i,0,up) {
		res+=dfs(p-1,(c+i),lim&&(i==up));
	}
	if(!lim) dp[p][c]=res;
	return res;
}

ll Solve(ll lim){
	c=0;
	while(lim) a[++c]=(lim&1),lim>>=1;
	return dfs(c,0,1);
}


int main(){
	memset(dp,-1,sizeof dp);
	scanf("%I64d",&m);
	k=rd();
	ll l=1,r=1e9,res=-1;
	r=r*r;
	while(l<=r) {
		ll mid=(l+r)>>1;
		//cout<<mid<<' '<<Solve(mid*2)-Solve(mid)<<endl;
		if(Solve(mid*2)-Solve(mid)>=m) r=mid-1,res=mid;
		else l=mid+1;
	}
	//cout<<Solve(res*2)-Solve(res)<<endl;
	printf("%lld\n",res);
}