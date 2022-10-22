/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=300000,M=300000;
int n,m;
char a[N+5];
vector<int> in[N+1];
struct ufset{
	int fa[2*M+3],sz[2*M+3];
	void init(){memset(fa,0,sizeof(fa));for(int i=1;i<=2*m+2;i++)sz[i]=i<=2*m&&i&1;}
	int root(int x){return fa[x]?fa[x]=root(fa[x]):x;}
	void mrg(int x,int y){x=root(x);y=root(y);if(x!=y)x>2*m&&(swap(x,y),0),fa[x]=y,sz[y]+=sz[x];}
	bool same(int x,int y){return root(x)==root(y);}
	int ask_sz(int x){return sz[x];}
}ufs;
int chc[M+2];
int main(){
	cin>>n>>m>>a+1;
	for(int i=1;i<=m;i++){
		int s;
		cin>>s;
		while(s--){
			int x;
			cin>>x;
			in[x].pb(i);
		}
	}
	ufs.init();
	for(int i=1;i<=m;i++)chc[i]=2*i;
	int ans=0,m0=2*m+2,m1=2*m+1;
	chc[m+1]=m1;
	for(int i=1;i<=n;i++){
		if(in[i].size()==1){
			int x=in[i][0],x0=2*x,x1=2*x-1;
			if(a[i]=='1'){
				if(!ufs.same(x0,m1)){
					ans+=-ufs.ask_sz(chc[ufs.root(x0)+1>>1])-ufs.ask_sz(m1);
					ufs.mrg(x0,m1);ufs.mrg(x1,m0);
					ans+=ufs.ask_sz(m1);
				}
			}
			else{
				if(!ufs.same(x1,m1)){
					ans+=-ufs.ask_sz(chc[ufs.root(x0)+1>>1])-ufs.ask_sz(m1);
					ufs.mrg(x1,m1);ufs.mrg(x0,m0);
					ans+=ufs.ask_sz(m1);
				}
			}
		}
		else if(in[i].size()==2){
			int x=in[i][0],y=in[i][1],x0=2*x,x1=2*x-1,y0=2*y,y1=2*y-1;
			if(a[i]=='1'){
				if(!ufs.same(x1,y1)){
					ans+=-ufs.ask_sz(chc[ufs.root(x0)+1>>1])-ufs.ask_sz(chc[ufs.root(y0)+1>>1]);
					ufs.mrg(x1,y1);ufs.mrg(x0,y0);
					if(ufs.root(x1)==m1)ans+=ufs.ask_sz(m1);
					else if(ufs.root(x1)==m0)ans+=ufs.ask_sz(m1);
					else{
						x=ufs.root(x0)+1>>1;x0=2*x;x1=2*x-1;
						if(ufs.ask_sz(x0)<ufs.ask_sz(x1))chc[x]=x0,ans+=ufs.ask_sz(x0);
						else chc[x]=x1,ans+=ufs.ask_sz(x1);
					}
				}
			}
			else{
				if(!ufs.same(x0,y1)){
					ans+=-ufs.ask_sz(chc[ufs.root(x0)+1>>1])-ufs.ask_sz(chc[ufs.root(y0)+1>>1]);
					ufs.mrg(x0,y1);ufs.mrg(x1,y0);
					if(ufs.root(x1)==m1)ans+=ufs.ask_sz(m1);
					else if(ufs.root(x1)==m0)ans+=ufs.ask_sz(m1);
					else{
						x=ufs.root(x0)+1>>1;x0=2*x;x1=2*x-1;
						if(ufs.ask_sz(x0)<ufs.ask_sz(x1))chc[x]=x0,ans+=ufs.ask_sz(x0);
						else chc[x]=x1,ans+=ufs.ask_sz(x1);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}