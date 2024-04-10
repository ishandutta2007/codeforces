#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int n,p[44];
int len,tot;
bool vis[44];
int mp[44];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1,len++;
	dfs(p[x]);
}
vector<int>all,num,cur;
int sz[1500];
vector<int>cnt[1500];
map<vector<int>,int>ID;
void get_state(int x,int Cnt){
	if(x==all.size()){
		++tot;
		cnt[tot]=cur,sz[tot]=Cnt;
		ID[cur]=tot;
		return;
	}
	for(int i=0;i<=num[x];i++){
		cur[x]=i;
		get_state(x+1,Cnt+all[x]*i);
	}
}
int C[44][44],fc[44];
int f[10][44][44][1500];
int dfs(int pos,int pre,int cur,int id){
	if(pos==all.size()){
		if(id==1)return 1;
		if(cur>0)return dfs(0,cur,0,id);
		return 0;
	}
	int &ret=f[pos][pre][cur][id];
	if(~ret)return ret;
	vector<int>vv=cnt[id];
	int tmp=1;
	if(vv[pos]>0){
		int zd=n-sz[id]-pre-cur;
		int mul=(ll)C[n][zd]*fc[zd]%M;
		int m1=1,m2=1;
		if(pre>0){
			m1=(ll)mul*C[n-zd-1][pre-1]%M*fc[pre]%M;
			m2=(ll)mul*C[n-zd-1][pre]%M*fc[pre]%M;
		}else m2=0;
		m1=(ll)m1*fc[n-zd-pre-1]%M;
		m2=(ll)m2*fc[n-zd-pre-1]%M;
		int lhp=1;
		for(int i=0;i<all[pos];i++){
			tmp=(ll)tmp*(m1+m2)%M;
			lhp=(ll)lhp*m2%M;
		}
		tmp=(tmp+M-lhp)%M;
	}
	ret=0;
	int NUM=vv[pos];
	for(int i=NUM,mm=1,s=0;~i;i--,mm=(ll)mm*tmp%M,s+=all[pos]){
		vv[pos]=i;
		(ret+=(ll)mm*dfs(pos+1,pre,cur+s,ID[vv])%M*C[NUM][i]%M)%=M;
	}
	return ret;
}
int main(){
	for(int i=0;i<44;i++){
		C[i][0]=1;
		fc[i]=i==0?1:(ll)fc[i-1]*i%M;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)if(!vis[i]){
		len=0,dfs(i);
		mp[len]++;
	}
	for(int i=1;i<=n;i++)if(mp[i]>0)all.push_back(i),num.push_back(mp[i]);
	cur.resize(all.size()),get_state(0,0);
	memset(f,-1,sizeof(f));
	printf("%d",dfs(0,0,0,tot));
}