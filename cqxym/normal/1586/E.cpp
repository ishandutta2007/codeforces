#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define N 300001
int f[N],dep[N],qx[N],qy[N];
vector<int>G[N];
bool tag[N];
inline int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
inline void DFS(int x,int F){
	f[x]=F;
	dep[x]=dep[F]+1;
	for(auto T:G[x]){
		if(T!=F){
			DFS(T,x);
		}
	}
}
inline void DP(int x,int&ans){
	int ct=0;
	for(auto T:G[x]){
		if(f[x]!=T){
			DP(T,ans);
			if(tag[T]==true){
				ct++;
			}
		}
	}
	ans+=ct>>1;
	ct&=1;
	if(tag[x]==false){
		ans+=ct;
	}
}
int main(){
	int n,m,x,y;
	cin>>n>>m;
	for(R i=1;i<=n;i++){
		f[i]=i;
	}
	for(R i=0;i!=m;i++){
		cin>>x>>y;
		if(GetF(x)!=GetF(y)){
			G[x].push_back(y);
			G[y].push_back(x);
			f[f[x]]=y;
		}
	}
	DFS(1,0);
	cin>>m;
	for(R i=0;i!=m;i++){
		cin>>x>>y;
		qx[i]=x;
		qy[i]=y;
		while(x!=y){
			if(dep[x]>dep[y]){
				tag[x]^=true;
				x=f[x];
			}else{
				tag[y]^=true;
				y=f[y];
			}
		}
	}
	int ans=0;
	DP(1,ans);
	if(ans!=0){
		cout<<"NO"<<endl<<ans;
	}else{
		cout<<"YES";
		for(R i=0;i!=m;i++){
			DFS(qy[i],0);
			x=qx[i];
			cout<<endl<<dep[x]<<endl;
			for(R j=x;j!=0;j=f[j]){
				cout<<j<<' ';
			}
		}
	}
	return 0;
}