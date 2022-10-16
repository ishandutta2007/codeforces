#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 998244353 
using namespace std;
int n,k,f[1005][2005][4];
inline int dfs(int step,int nowk,int now){
	if (step==n){
		if (nowk==k)return 1;
		return 0;
	}
	if (nowk>k)return 0;
	if (f[step][nowk][now]!=-1)return f[step][nowk][now];
	int s=0;
	if (now==0){
		s+=dfs(step+1,nowk,0);s%=mod;
		s+=dfs(step+1,nowk+1,1);s%=mod;
		s+=dfs(step+1,nowk+1,2);s%=mod;
		s+=dfs(step+1,nowk+1,3);s%=mod;
	}
	else if (now==1){
		s+=dfs(step+1,nowk,0);s%=mod;
		s+=dfs(step+1,nowk,1);s%=mod;
		s+=dfs(step+1,nowk+2,2);s%=mod;
		s+=dfs(step+1,nowk,3);s%=mod;
	}
	else if (now==2){
		s+=dfs(step+1,nowk,0);s%=mod;
		s+=dfs(step+1,nowk+2,1);s%=mod;
		s+=dfs(step+1,nowk,2);s%=mod;
		s+=dfs(step+1,nowk,3);s%=mod;
	}
	else if (now=3){
		s+=dfs(step+1,nowk+1,0);s%=mod;
		s+=dfs(step+1,nowk+1,1);s%=mod;
		s+=dfs(step+1,nowk+1,2);s%=mod;
		s+=dfs(step+1,nowk,3);s%=mod; 
	}
	return f[step][nowk][now]=s;
}
signed main(){
//	freopen("1051D.in","r",stdin);
//	freopen("1051D.out","w",stdout);
	cin>>n>>k;
	memset(f,-1,sizeof(f));
	cout<<(dfs(1,1,0)+dfs(1,2,1)+dfs(1,2,2)+dfs(1,1,3))%mod<<endl;
	return 0;
}