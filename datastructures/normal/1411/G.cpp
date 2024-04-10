#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int n,m,u[100005],v[100005],first[100005],nxt[100005];
int deg[100005],q[100005],head,tail,book[605],sg[100005];
int cnt[605];
int mat[605][605];
vector<int> e[100005];
void gauss(){
	for (int i=0;i<=511;i++){
		int id=i;
		while(mat[id][i]==0&&id<=511)id++;
		if (id!=i){
			for (int j=0;j<=512;j++)
				swap(mat[id][j],mat[i][j]);
		}
		for (int j=0;j<=511;j++){
			if (j==i)continue;
			int qwq=1ll*mat[j][i]*inv(mat[i][i])%mod;
			for (int k=0;k<=512;k++)mat[j][k]=(mat[j][k]+mod-1ll*qwq*mat[i][k]%mod)%mod;
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++;
		nxt[i]=first[u[i]],first[u[i]]=i;
		e[v[i]].push_back(u[i]); 
	}
	head=1,tail=0;
	for (int i=1;i<=n;i++)
		if (deg[i]==0)q[++tail]=i;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=first[now];i;i=nxt[i])
			book[sg[v[i]]]=1;
		for (int i=0;i<=511;i++)
			if (book[i]==0){
				sg[now]=i;
				break;
			}
		cnt[sg[now]]++;
		for (int i=first[now];i;i=nxt[i])
			book[sg[v[i]]]=0;
		for (int i=0;i<e[now].size();i++){
			deg[e[now][i]]--;
			if (deg[e[now][i]]==0)q[++tail]=e[now][i];
		}
	}
	for (int i=0;i<=511;i++){
		mat[i][512]=1ll*cnt[i]*inv(n+1)%mod;
		for (int j=0;j<=511;j++){
			if (i==j)mat[i][j]=(1ll*cnt[0]*inv(n+1)%mod+mod-1)%mod;
			else mat[i][j]=1ll*cnt[i^j]*inv(n+1)%mod;
		}
	}
	gauss();
	cout<<(1+1ll*mat[0][512]*inv(mat[0][0])%mod*inv(n+1)%mod-inv(n+1)+mod)%mod<<endl;
}