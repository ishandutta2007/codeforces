#include<bits/stdc++.h>
using namespace std;
const int o=(1<<20)+10;
int n,c,rep[o],ask[o],q,f[o],g[o],ppc[o],z[o],gs;bool vis[o],in[o];pair<int,bool> pr[o];vector<int> V;
mt19937 rnd(time(0));
struct linear_base{
	int v[21],mask[21];vector<int> vec;
	pair<int,bool> insert(int x){
		int t=x,msk=0;
		for(int i=20;i+1;--i) if((x>>i)&1)
			if(!v[i]){
				mask[i]=msk|(1<<vec.size());vec.push_back(t);v[i]=x;
				return make_pair(mask[i],true);
			}
			else msk^=mask[i],x^=v[i];
		return make_pair(msk,false);
	}
}B[o];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n;
	for(int i=1;i<=c;++i) rep[i]=1;
	for(int i=2;i<=c;++i) for(int j=2*i;j<=c;j+=i) vis[j]=1;
	for(int i=2;i<=c;++i) if(!vis[i]) for(int j=i;j<=c;j+=i) rep[j]*=i;
	for(int i=1;i<=c;++i) if(rep[i]==i) ask[++q]=i;
	cout<<q<<endl;
	for(int i=1;i<=q;++i) cout<<ask[i]<<" ";
	cout<<endl;
	for(int i=1;i<=q;++i) cin>>f[ask[i]];
	for(int i=c;i>1;--i) if(rep[i]==i) f[i]^=f[1];
	for(int i=2;i<=c;++i) for(int j=i;j<=c;j+=i) if(rep[j]==j) g[j]^=f[i];
	g[1]=f[1];
	for(int i=c;i;--i) if(rep[i]==i) for(int j=2*i;j<=c;j+=i) g[i]^=g[j];
	for(int i=1;i<o;++i) ppc[i]=ppc[i>>1]+(i&1);
	for(int i=1;i<=c;++i) if(rep[i]==i){
		for(int j=i;j<=c;j+=i) if(rep[j]==i) if(!(pr[j]=B[i].insert(j)).second) V.push_back(j);
		gs+=ppc[z[i]=B[i].insert(g[i]).first];
		for(int j=0,sz=B[i].vec.size();j<sz;++j) if((z[i]>>j)&1) in[B[i].vec[j]]=1;
	}
	for(int i;gs^n;){
		gs-=in[i=V[rnd()%V.size()]];in[i]^=1;gs+=in[i]-ppc[z[rep[i]]];gs+=ppc[z[rep[i]]^=pr[i].first];
		for(int j=0,sz=B[rep[i]].vec.size();j<sz;++j) if((pr[i].first>>j)&1) in[B[rep[i]].vec[j]]^=1;
	}
	for(int i=1;i<=c;++i) if(in[i]) cout<<i<<" ";
	cout<<endl;
	return 0;
}