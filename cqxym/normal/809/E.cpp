#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 200001
#define P 1000000007
I int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int a[N],pos[N],phi[N],s[N],dp1[N],dp2[N],prime[N],Top[N],h[N],sz[N],f[N],dep[N],sum[100001],in[N],out[N],ct;
bool vis[N],tag[N];
vector<int>G[N],H[N];
I void PreDFS(int x,int F){
	f[x]=F;
	dep[x]=dep[F]+1;
	sz[x]=1;
	for(int T:G[x]){
		if(T!=F){
			PreDFS(T,x);
			sz[x]+=sz[T];
			if(sz[T]>sz[h[x]]){
				h[x]=T;
			}
		}
	}
}
I void ReDFS(int x,int t,int&ct){
	ct++;
	in[x]=ct;
	Top[x]=t;
	if(h[x]!=0){
		ReDFS(h[x],t,ct);
		for(int T:G[x]){
			if(T!=f[x]&&T!=h[x]){
				ReDFS(T,T,ct);
			}
		}
	}
	out[x]=ct;
}
I void DP(int x){
	dp1[x]=tag[x]==true?phi[a[x]]:0;
	dp2[x]=0;
	for(int T:H[x]){
		DP(T);
		dp2[x]=((L)dp1[x]*dp1[T]+dp2[x])%P;
		dp1[x]+=dp1[T];
		if(dp1[x]>=P){
			dp1[x]-=P;
		}
	}
}
int main(){
	s[0]=phi[1]=1;
	int n,t=0,x,y,ans=0;
	scanf("%d",&n);
	for(R i=2;i<=n;i++){
		if(vis[i]==false){
			prime[t]=i;
			t++;
			phi[i]=i-1;
		}
		for(R j=0;prime[j]*i<N;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		pos[a[i]]=i;
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	PreDFS(1,0);
	t=0;
	ReDFS(1,1,t);
	auto LCA=[](int x,int y){
		while(Top[x]!=Top[y]){
			if(dep[Top[x]]>dep[Top[y]]){
				x=f[Top[x]];
			}else{
				y=f[Top[y]];
			}
		}
		return dep[x]<dep[y]?x:y;
	};
	auto Clear=[](int x){vector<int>().swap(H[x]);};
	auto Link=[](int x,int y){H[x].push_back(y);};
	for(R i=1;i<=n>>1;i++){
		vector<int>A,B;
		for(R j=i;j<=n;j+=i){
			if(pos[j]!=1){
				A.push_back(pos[j]);
			}
			tag[pos[j]]=true;
		}
		sort(A.begin(),A.end(),[](int x,int y){return in[x]<in[y];});
		Clear(1);
		t=0;
		for(int T:A){
			Clear(T);
			if(in[T]<in[s[t]]||in[T]>out[s[t]]){
				x=LCA(s[t],T);
				while(t!=0&&dep[s[t-1]]>dep[x]){
					Link(s[t-1],s[t]);
					t--;
				}
				if(s[t-1]==x){
					Link(x,s[t]);
					t--;
				}else{
					Clear(x);
					Link(x,s[t]);
					s[t]=x;
					B.push_back(x);
				}
			}
			t++;
			s[t]=T;
		}
		while(t!=0){
			Link(s[t-1],s[t]);
			t--;
		}
		if(a[1]%i!=0){
			B.push_back(1);
		}
		DP(1);
		int sumphi=dp1[1];
		for(R j=i;j<=n;j+=i){
			tag[pos[j]]=false;
			sum[i]=((2ll*(sumphi-phi[j])*phi[j]-4ll*dp2[pos[j]])%P*dep[pos[j]]+sum[i])%P;
		}
		for(int T:B){
			sum[i]=(sum[i]-4ll*dp2[T]*dep[T])%P;
		}
	}
	for(R i=n>>1;i!=0;i--){
		if(sum[i]<0){
			sum[i]+=P;
		}
		for(R j=i<<1;j<=n>>1;j+=i){
			sum[i]-=sum[j];
			if(sum[i]<0){
				sum[i]+=P;
			}
		}
		ans=((L)i*GetInv(phi[i])%P*sum[i]+ans)%P;
	}
	printf("%d",(L)ans*GetInv((n-1ll)*n%P)%P);
	return 0;
}