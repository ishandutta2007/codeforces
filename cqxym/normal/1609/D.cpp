#include<iostream>
#include<queue>
using namespace std;
#define R register int
int f[1001],sz[1001];
inline int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
int main(){
	int n,d,x,y,t=1;
	cin>>n>>d;
	for(R i=1;i<=n;i++){
		f[i]=i;
		sz[i]=1;
	}
	for(R i=0;i!=d;i++){
		cin>>x>>y;
		if(GetF(x)==GetF(y)){
			t++;
		}else{
			sz[f[y]]+=sz[f[x]];
			f[f[x]]=y;
		}
		priority_queue<int>Q;
		for(R j=1;j<=n;j++){
			if(GetF(j)==j){
				Q.push(sz[j]);
			}
		}
		int ans=-1;
		for(R j=0;j!=t;j++){
			ans+=Q.top();
			Q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}