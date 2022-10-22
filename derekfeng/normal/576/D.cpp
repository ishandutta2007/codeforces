#include<bits/stdc++.h>
using namespace std;
int n,m,u[151],v[151],c[151],ans=1e9+200;
int cnt,head[151],nxt[151],to[151];
void adde(int f,int t){
	++cnt;
	to[cnt]=t,nxt[cnt]=head[f],head[f]=cnt;
}
vector<int>all;
bitset<151>now;
struct mat{
	bitset<151>A[151];
	mat(){for(int i=0;i<151;i++)A[i].reset();}
};
mat operator * (mat a,mat b){
	mat ans;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(a.A[i][j])
			ans.A[i]|=b.A[j];
	return ans;
}
void matpow(int x,int t){
	mat ini,ans;
	for(int i=0;i<m;i++)if(c[i]<=x)ini.A[u[i]][v[i]]=1;
	for(int i=1;i<=n;i++)if(now[i])ans.A[i][i]=1;
	while(t){
		if(t&1)ans=ans*ini;
		ini=ini*ini,t>>=1;
	}
	now.reset();
	for(int i=1;i<=n;i++)now|=ans.A[i];
}
int d[151];
void check(int x){
	cnt=0;
	for(int i=1;i<=n;i++)head[i]=0,d[i]=-1;
	for(int i=0;i<m;i++)if(c[i]<=x)adde(v[i],u[i]);
	queue<int>que;d[n]=0,que.push(n);
	while(!que.empty()){
		int f=que.front();que.pop();
		if(now[f])ans=min(ans,x+d[f]);
		for(int i=head[f];i;i=nxt[i])if(d[to[i]]<0)
			d[to[i]]=d[f]+1,que.push(to[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	all.push_back(0);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u[i],&v[i],&c[i]),all.push_back(c[i]);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	now[1]=1;
	for(int i=0;i<all.size();i++){
		if(i>0)matpow(all[i-1],all[i]-all[i-1]);
		if(ans<=all[i])break;
		check(all[i]);
	}
	if(ans>1e9+150)puts("Impossible");
	else printf("%d",ans);
}