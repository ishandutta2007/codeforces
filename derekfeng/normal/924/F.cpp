#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<100>f;
int num[10];
vector<int>v[40000];
int tot,nxt[40000][10];
ll dp[22][2],pd[22][2];
ll ff[22][40000][2],gg[22][40000][10][2];
unordered_map<ll,int>ump;
void dfs(int x,vector<int>tmp,int N,int pr,int val){
	if(x==10){
		ll hsh=0;
		for(auto y:tmp)hsh=hsh*10+y;
		if(ump.find(hsh)==ump.end())ump[hsh]=++tot,v[tot]=tmp;
		if(tmp.size()==N)ff[0][ump[hsh]][pr]++,gg[0][ump[hsh]][val][pr]++;
		return;
	}
	for(int i=0;i<=num[x];i++){
		if(i>0)tmp.push_back(x);
		dfs(x+1,tmp,N,pr,val);
	}
}
void getstate(int x,int y,int s){
	int v;
	for(int i=s/2;;i--)if(f[i]){v=s-2*i;break;}
	if(v>1)dfs(1,vector<int>{},x,s&1,v);
	if(x==18)return;
	for(int i=y;i<=9;i++){
		bitset<100>nf=f;
		f=nf|(nf<<i),num[i]++;
		getstate(x+1,i,s+i);
		f=nf,num[i]--;
	}
}
void gettrans(){
	for(int i=1;i<=tot;i++)for(int j=0;j<10;j++){
		vector<int>tmp=v[i];
		if(j>0)tmp.push_back(j);
		sort(tmp.begin(),tmp.end());
		ll hsh=0;
		for(auto y:tmp)hsh=hsh*10+y;
		nxt[i][j]=ump[hsh];
	}
}
ll samelen(vector<int>&dig,int K){
	ll val[2]={0,0},ans=0,Pre=0;
	int n=dig.size(),cur=1;
	for(int i=0;i<n;i++){
		if(i>0)Pre+=dig[i-1],cur=nxt[cur][dig[i-1]];
		for(int j=(i>0?0:1);j<dig[i];j++){
			for(int k=0;k<2;k++)val[(Pre+j+k)&1]+=dp[n-i-1][k];
			if(cur!=0){
				for(int k=0;k<2;k++)val[(Pre+j+k)&1]-=ff[n-i-1][nxt[cur][j]][(Pre+j+k)&1];
				for(int k=0;k<2;k++)ans+=gg[n-i-1][nxt[cur][j]][K][(Pre+j+k)&1];
			}
		}
	}
	ans+=val[0];
	if(K>0)ans+=val[1];
	return ans;
}
ll qry(ll x,int K){
	if(x==0)return 0;
	vector<int>dig;
	ll xx=x;
	do{dig.push_back(xx%10),xx/=10;}while(xx>0);
	reverse(dig.begin(),dig.end());
	int n=dig.size();
	ll ans=0;
	for(int i=1;i<n;i++){
		ll val[2]={0,0};
		for(int j=1;j<10;j++)for(int k=0;k<2;k++){
			val[(j+k)&1]+=dp[i-1][k];
			val[(j+k)&1]-=ff[i-1][nxt[1][j]][(j+k)&1];
			ans+=gg[i-1][nxt[1][j]][K][k];
		}
		ans+=val[0];
		if(K>0)ans+=val[1];
	}
	return ans+samelen(dig,K);
}
int main(){
	f[0]=1,getstate(0,1,0),gettrans();
	dp[0][0]=1;
	for(int i=1;i<20;i++)for(int j=0;j<2;j++)if(dp[i-1][j])
		for(int k=0;k<10;k++)dp[i][(j+k)&1]+=dp[i-1][j];
	for(int i=1;i<20;i++)for(int j=1;j<=tot;j++)for(int k=0;k<2;k++)
		for(int l=0;l<10;l++)ff[i][j][k]+=ff[i-1][nxt[j][l]][k];
	for(int i=1;i<20;i++)for(int j=1;j<=tot;j++)for(int k=2;k<10;k++)for(int l=0;l<2;l++)
		for(int p=0;p<10;p++)gg[i][j][k][l]+=gg[i-1][nxt[j][p]][k][l];
	for(int i=0;i<20;i++)for(int j=1;j<=tot;j++)
		for(int k=2;k<10;k++)for(int l=0;l<2;l++)gg[i][j][k][l]+=gg[i][j][k-1][l];
	int Tc;scanf("%d",&Tc);
	ll l,r,k;
	while(Tc--)scanf("%lld%lld%lld",&l,&r,&k),printf("%lld\n",qry(r+1,k)-qry(l,k));
}