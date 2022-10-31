#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n;
int s[N],to[N];
int v[N];
int cr;
pair<int,int> f[2][N],g[2][N],ans;
vector<pair<int,int>> res;
int pr[N],cs[N];
pair<int,int> operator + (pair<int,int> a,pair<int,int> b){
	return make_pair(a.first+b.first,a.second+b.second);
}

void getcir(int k){
	v[k]=1;
	if(v[to[k]])cr=k;
	else getcir(to[k]);
}

void dfs(int k,int rt){
	f[0][k]=f[1][k]=make_pair(0,0);
	v[k]=1;
	fore(k)if(_to!=rt){
		dfs(_to,rt);
		f[1][k]=max(f[0][k]+make_pair(1,s[k]!=s[_to])+f[0][_to],f[1][k]+f[1][_to]);
		f[0][k]=f[0][k]+f[1][_to];
	}
	f[1][k]=max(f[0][k],f[1][k]);
}

void df5(int k,int rt){
	g[0][k]=g[1][k]=make_pair(0,0);
	v[k]=1;
	fore(k)if(_to!=rt){
		df5(_to,rt);
		g[1][k]=max(g[0][k]+make_pair(1,s[k]!=s[_to])+g[0][_to],g[1][k]+g[1][_to]);
		g[0][k]=g[0][k]+g[1][_to];
	}
	g[1][k]=max(g[0][k],g[1][k]);
}

void df4(int k,int rt){
	f[0][k]=f[1][k]=make_pair(0,0);
	v[k]=1;
	fore(k)if(_to!=rt){
		df4(_to,rt);
		if(f[0][k]+make_pair(1,s[k]!=s[_to])+f[0][_to]>f[1][k]+f[1][_to])
			pr[k]=_to;
		f[1][k]=max(f[0][k]+make_pair(1,s[k]^s[_to])+f[0][_to],f[1][k]+f[1][_to]);
		f[0][k]=f[0][k]+f[1][_to];
	}
	if(f[1][k]>f[0][k])
		cs[k]=1;
	f[1][k]=max(f[0][k],f[1][k]);
}

void df6(int k,int rt,int fl){
	int nf=0;
	if(fl&&cs[k])nf=1,res.push_back({k,pr[k]});
	fore(k)if(_to!=rt){
		if(nf&&_to==pr[k])df6(_to,rt,0);
		else df6(_to,rt,1);
	}
}

void getfa(int k){
	df4(k,k);
	df6(k,k,f[0][k]<f[1][k]);
}

void calc(int k){
	getcir(k);
	dfs(cr,cr);
	df5(to[cr],to[cr]);
	ans=ans+max(f[1][cr],g[1][to[cr]]);
	if(f[1][cr]>g[1][to[cr]]) getfa(cr);
	else getfa(to[cr]);
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>to[i]>>s[i];
		add(to[i],i);
	}
	for(int i=1;i<=n;i++)
		if(!v[i])calc(i);
	cout<<ans.first<<' '<<ans.second<<endl;
	for(auto x:res)cout<<x.first<<' '<<x.second<<'\n';
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}