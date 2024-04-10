#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1<<20|5;
typedef long long ll;
namespace SOLVE1{
	vector<ll> s[2][2][2];
	void dfs(vector<ll>& a,int x,ll sum,int type1,int type2,int id){
		if(x>=a.size()){
			s[id][type1][type2].push_back(sum);
			return;
		}
		dfs(a,x+1,sum+a[x],type1,1,id);
		dfs(a,x+1,sum-a[x],1,type2,id);
	}
	bool check(vector<ll> a,vector<ll> b,int top){
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int poi=0;
		if(a.empty()||b.empty()) return false;
//		for(auto x:a) printf("|%lld|",x); puts("");
//		for(auto y:b) printf("|%lld|",y); puts("");
//		puts("-------------------");
		for(int i=(int)b.size()-1;i>=0;--i){
			while(poi+1<a.size()&&a[poi]+b[i]<-top) ++poi;
			if(abs(a[poi]+b[i])<=top) return true;
		}
		return false;
	}
	bool solve(vector<ll> a){
		if(a.size()<2) return false;
		ll sum=0;
		for(auto x:a) sum+=x;
//		printf("[%lld %d]",sum,(int)(a.size()-1));
		if((sum&1)!=((int)(a.size()-1)&1)) return false;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					s[i][j][k].clear();
		int m=(int)a.size()/2;
		vector<ll> x(a.begin(),a.begin()+m),y(a.begin()+m,a.end());
		dfs(x,0,0,0,0,0);
		dfs(y,0,0,0,0,1);
//		for(auto x:a) printf("(%lld)\n",x); puts("");
		int t=((int)a.size()-1)&1;
		for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int x=0;x<2;++x)
			for(int y=0;y<2;++y)
				if(i+x>0&&j+y>0){
					if(check(s[0][i][j]
							,s[1][x][y],(int)a.size()-1))
						return true;
					}
		return false;
	}
	bool solve1(vector<ll> a){
		for(int sta=1;sta<(int)(1<<a.size())-1;++sta){
			ll sum=0;
			for(int i=0;i<a.size();++i)
				if(sta&(1<<i)) sum+=a[i];
				else sum-=a[i];
			if(((sum&1)==((int)(a.size()-1)&1))&&(abs(sum)<(int)a.size())) 
				return true;
		}
		return false;
	}
}
int cnt[MAX_N];
struct Initer{
	Initer(){
		cnt[0]=0;
		for(int i=1;i<1<<20;++i)
			cnt[i]=cnt[i-(i&-i)]+1;
	}
}__initer;
namespace SOLVE2{
	int f[25][MAX_N],g[25][MAX_N],h[25][MAX_N];
	inline void FWT(int a[],int n){
		for(int s=1,sx=2;s<n;sx=(s=sx)<<1)
			for(int i=0;i<n;i+=sx)
				for(int j=i;j<i+s;++j)
					a[j+s]+=a[j];
	}
	inline void DFWT(int a[],int n){
		for(int s=1,sx=2;s<n;sx=(s=sx)<<1)
			for(int i=0;i<n;i+=sx)
				for(int j=i;j<i+s;++j)
					a[j+s]-=a[j];
	}
	void FMT2(int a[],int b[],int c[],int n){
		vector<int> g;
		g.clear();
		for(int i=0;i<1<<n;++i) 
			if(a[i]) g.push_back(i);
//		for(int i=0;i<1<<n;++i) printf("(%d)",a[i]); puts("");
//		for(int i=0;i<1<<n;++i) printf("(%d)",b[i]); puts("");
		for(int i=0;i<1<<n;++i){
			c[i]=0;
			for(auto x:g)
				if(((i&x)==x)&&b[i-x]){
					c[i]=1;
					break;
				}
		}
//		for(int i=0;i<1<<n;++i) printf("[%d]",c[i]); puts("");
	}
	void FMT3(int a[],int b[],int c[],int n){
		for(int i=0;i<1<<n;++i){
			c[i]=0;
			if(b[i]&&a[0]){
				c[i]=1;
				continue;
			}
			for(int j=i;j>0;j=(j-1)&i){
				if(a[j]&&b[i-j]){
					c[i]=1;
					break;
				}
			}
		}
	}
	void FMT(int a[],int b[],int c[],int n,int type=0){
//		FMT3(a,b,c,n);
//		return;
//		for(int i=0;i<1<<n;++i) printf("[%d]",a[i]); puts("");
//		for(int i=0;i<1<<n;++i) printf("[%d]",b[i]); puts("");
		for(int l=0;l<=n;++l){
			memset(f[l],0,sizeof(int)*(1<<n));
			memset(g[l],0,sizeof(int)*(1<<n));
		}
		int cnt1=0,cnt2=0;
		for(int i=0;i<1<<n;++i){
			f[cnt[i]][i]=a[i];
		 	g[cnt[i]][i]=b[i];
			cnt1+=a[i];
			cnt2+=b[i];
		}
		if(cnt1<=100||cnt2<=100){
			if(cnt1<cnt2) FMT2(a,b,c,n);
			else FMT2(b,a,c,n);
			return;
		}
		if(1ll*cnt1*cnt2>=1ll*(1<<n)*(1<<n)/4){
			FMT3(a,b,c,n);
			return;
		}
		for(int l=0;l<=n;++l){
			FWT(f[l],1<<n);
			if(!type) FWT(g[l],1<<n);
			else memcpy(g[l],f[l],sizeof(int)*(1<<n));
		}
		for(int l=0;l<=n;++l){
			memset(h[l],0,sizeof(int)*(1<<n));
			for(int s=0;s<=l;++s)
				for(int i=0;i<1<<n;++i)
					h[l][i]+=f[s][i]*g[l-s][i];	
			DFWT(h[l],1<<n);
		}
		for(int i=0;i<1<<n;++i)
			c[i]=h[cnt[i]][i]>0;
//		for(int i=0;i<1<<n;++i) printf("{%d}",c[i]); puts("");
	}
	int b1[23][MAX_N],c[MAX_N];
	int solve(int a[],int b[],int n){
		memcpy(b1[0],b,sizeof(int)*(1<<n));
		for(int i=1;i<=4;++i)
			FMT(b1[i-1],b1[i-1],b1[i],n,1);
		int ret=0;
		for(int i=4;i>=0;--i){
			FMT(a,b1[i],c,n);
			bool flag=0;
			for(int j=0;j<1<<n;++j)
				if(c[j]!=0){
					flag=1;
					break;
				}
			if(flag){
				ret+=1<<i;
				memcpy(a,c,sizeof(int)*(1<<n));
			}
		}
		return ret;
	}		
}
int g[MAX_N],f[MAX_N];
ll a[MAX_N];
int main(){
//	freopen("1.in","r",stdin);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
		while(i<=n&&a[i]==0){
			swap(a[i],a[n]);
			--n;
		}
//	printf("|%d|",n);
	if(n==0){
		puts("0");
		return 0;
	}
	for(int sta=0;sta<1<<n;++sta){
		if(cnt[sta]<=1){
			g[sta]=0;
			continue;
		}
		vector<ll> b;
		for(int i=1;i<=n;++i)
			if(sta&(1<<i-1)){
				b.push_back(a[i]);
				if(g[sta-(1<<i-1)]){
					g[sta]=1;
					break;
				}
			}
		if(!g[sta]){
			g[sta]=SOLVE1::solve(b);
/*			if(g[sta]!=SOLVE1::solve1(b)){
				for(auto x:b) printf("[%lld]",x);
				printf("{%d}",g[sta]);
				puts("GG");
				exit(0);
			}
*/		}
	}
//	exit(0);
//	for(int sta=0;sta<1<<n;++sta)
//		if(g[sta]) 
//		printf("(%d %d)",sta,g[sta]);
//	exit(0);
	for(int i=0;i<1<<n;++i) f[i]=1;
	printf("%d\n",max(0,n-SOLVE2::solve(f,g,n)));
	return 0;
}