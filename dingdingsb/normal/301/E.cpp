#include<bits/stdc++.h>
int n,m,p;
unsigned long long Pow[1000];
#define SJY_AK_IOI 100007
const unsigned long long b=SJY_AK_IOI;
namespace solve1{
	// 30pts
	//60pts
	//
	//1  
	//<p
	std::map<unsigned long long,bool>m;
	int flag[120][120];
	//
	//p+1 
	//p+1
	//p+1
	//
	// 
	void work(){
		//
		//
		//
		//2
			
	}                                                         
} //..
namespace solve2{
	std::vector<int>ans[1000000];int tot=0;
	unsigned long long hash[1000000];
	int max[1000000];
	void dfs(int now,std::vector<int> V){
		if(now>n)return;
		std::vector<int>tmp;
		if(V[V.size()-1]==2)ans[++tot]=V;
		tmp=V;if(tmp[tmp.size()-1]-1>=1)
		tmp.push_back(tmp[tmp.size()-1]-1),dfs(now+1,tmp);
		tmp=V;if(tmp[tmp.size()-1]+1<=m)
		tmp.push_back(tmp[tmp.size()-1]+1),dfs(now+1,tmp);
	}
	void work(){
		std::vector<int>v;
		v.push_back(1);
		dfs(1,v);
		std::map<unsigned long long,int>M;
		std::map<unsigned long long,int>U;
		for(int i=1;i<=tot;i++){
			hash[i]=0;
			for(int j=0;j<ans[i].size();j++)
				//printf("%d ",ans[i][j]),
				hash[i]+=Pow[ans[i][j]],
				max[i]=std::max(max[i],ans[i][j]);
			M[hash[i]]++;
		}
		int ans1=0;
		for(int i=1;i<=tot;i++)
			if(!U[hash[i]]){
				//for(int j=0;j<ans[i].size();j++)
				//	printf("%d ",ans[i][j]);
				//printf("\n");
				ans1+=(m-max[i]+1);
				//printf("%d\n",(m-max[i]+1)); 
				U[hash[i]]++;
			}
		std::cout<<ans1;
	}
} 
namespace solve3{
	const int mod=1e9+7;
	#define ll long long
	#define int long long
	inline int add(int a,int b){return (a+=b)>=mod?(a-mod):a;}
	inline int dec(int a,int b){a-=b;return a+(a>>31&mod);}
	inline int mul(int a,int b){static ll r;r=1ll*a*b;return (r>=mod)?(r%mod):r;}
	inline void Add(int &a,int b){(a+=b)>=mod?(a-=mod):0;}
	inline void Dec(int &a,int b){a-=b,a+=a>>31&mod;}
	inline void Mul(int &a,int b){static ll r;r=1ll*a*b;a=(r>=mod)?(r%mod):r;}
	inline int ksm(int a,int b,int res=1){if(a==0&&b==0)return 0;for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
	inline int Inv(int x){return ksm(x,mod-2);}
	inline int fix(int x){return (x<0)?x+mod:x;}
	const int N=105;
	int f[2][N][N][N],c[N][N];
	void work(){
		int K=p;
		for(int i=0;i<N;i++){
			c[i][0]=c[i][i]=1;
			for(int j=1;j<i;j++)
			c[i][j]=add(c[i-1][j],c[i-1][j-1]);
		}
		int cur=0,res=0;
		for(int i=1;i<=m;i++){
			cur^=1;
			memset(f[cur],0,sizeof(f[cur]));
			for(int j=1;j<=n;j++)
			for(int k=1;k<=j;k++)
			for(int l=1;l<=K;l++)if(f[cur^1][j][k][l]){
				int now=f[cur^1][j][k][l];
				for(int p=k;j+p<=n&&l*c[p-1][k-1]<=K;p++){
					Add(f[cur][j+p][p-k][l*c[p-1][k-1]],now);
				}
			}
			for(int j=1;j<=n;j++)Add(f[cur][j][j][1],1);
			for(int j=1;j<=n;j++)
			for(int k=1;k<=K;k++)
			Add(res,f[cur][j][0][k]);
		}
		std::cout<<res<<'\n';
	}
} 
signed main(){
	//freopen("seq.in","r",stdin);
	//freopen("seq.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	Pow[0]=1;for(int i=1;i<=100;i++)Pow[i]=b*Pow[i-1];
	//if(n<=15&&m<=15)solve2::work();
	//else if(n==84&&m==89&&p==81)printf("71189272");
	/*else*/ solve3::work();
}