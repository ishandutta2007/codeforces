#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
vector<int>v[150003],bit[150003],large;
int sz[150003],head[150003],pa[150003],n,T,pos[150003],cnt[150003],cntt[303][150003];
int dfs(int x,int p){
	int siz=1;pa[x]=p;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			siz+=dfs(v[x][i],x);
	sz[x]=siz;
	return siz;
}
void poufen(int x,int tou,int p,int po){
	head[x]=tou;pos[x]=po;
	bit[tou].push_back(0);
	pair<int,int>res=make_pair(0,-1); 
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			res=max(res,make_pair(sz[v[x][i]],v[x][i]));
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			if(v[x][i]==res.second)
				poufen(v[x][i],tou,x,po+1);
			else
				poufen(v[x][i],v[x][i],x,0);
}
int dfs2(int x,int p){
	int siz=1;pa[x]=p;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			siz+=dfs2(v[x][i],x);
	sz[x]=siz;
	return siz;
} 
void dfs3(int x,int p,int minn){
	cntt[large.size()][x]=minn;
	for(long long i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			dfs3(v[x][i],x,min(minn,n-sz[v[x][i]]));
}
int sum(int x,int y){
	int ret=0;
	while(y>0){
		ret=(bit[x][y]+ret)%mod;
		y=y-(y&(-y));
	}
	return ret;
}
void add(int x,int y,int a){
	while(y<bit[x].size()){
		bit[x][y]=(bit[x][y]+a)%mod;
		y+=(y&(-y));
	}
}
long long quickpow(long long a,int b){
	if(b<0)return 0;
	long long ret=1;
	a%=mod;
	while(b){
		if(b%2)ret=(ret*a)%mod;
		b/=2;a=(a*a)%mod;
	}
	return ret;
}
int main(){
	cin>>n>>T;
	long long inv=quickpow(n,mod-2);
	for(int i=0;i<n;i++)
		bit[i].push_back(0);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<n;i++)
		if(v[i].size()>500){
			dfs2(i,-1);
			dfs3(i,-1,n);
			large.push_back(i);
		}
	dfs(0,-1);poufen(0,0,-1,0);
	while(T--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int x,d;
			scanf("%d%d",&x,&d);
			x--;
			if(v[x].size()>500)
				cnt[x]=(cnt[x]+d)%mod;
			else{
				long long tmp=sz[x];
				tmp*=d;tmp%=mod;
				add(0,1,tmp);
				tmp=n-sz[x];
				tmp*=d;tmp%=mod;
				add(head[x],pos[x]+1,tmp);
				for(int i=0;i<v[x].size();i++)
					if(v[x][i]!=pa[x]){
						tmp=-sz[v[x][i]];tmp*=d;tmp%=mod;
						tmp+=mod;tmp%=mod;
						add(head[v[x][i]],pos[v[x][i]]+1,tmp);
					}
			}
		}else{
			int x;scanf("%lld",&x);
			x--;int res=0;long long tmp; 
			for(int i=0;i<large.size();i++)
			{
				tmp=cnt[large[i]];
				tmp=tmp*cntt[i][x]%mod;
				res=(res+tmp)%mod;
			}
			while(x!=-1){
				res=(res+sum(head[x],pos[x]+1))%mod;
				x=pa[head[x]];
			}
			long long ans=res;
			ans*=inv;
			printf("%lld\n",ans%mod);
		}
	} 
}