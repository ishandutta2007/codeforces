#include<bits/stdc++.h>
//#define int long long
const int N=5005;
using namespace std;

int n,X,dfn[N],cnt,fa[N];
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}
void qry(int n){cout<<"? "<<n;for(int i=1;i<=n;i++)cout<<' '<<dfn[i];cout<<endl;}
void dfs(int k,int f){
	dfn[++cnt]=k;
	fa[k]=f;
	fore(k)if(_to!=f){
		dfs(_to,k);
	} 
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)dfn[i]=i;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
	qry(n); 
	cin>>X;
	dfs(1,0);
	int l=2,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)>>1,nw;
		qry(mid);
		cin>>nw;
		if(nw==X)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<dfn[ans]<<' '<<fa[dfn[ans]]<<endl;
}