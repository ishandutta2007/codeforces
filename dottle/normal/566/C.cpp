#include<bits/stdc++.h>
const int N=1005000;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
#define nfa if(_to!=fa)
#define nvs if(!v[_to])
struct edge{
    int to,nx,w;
}e[N];int hd[N],S;
void add(int fr,int to,int w){
    e[++S]=(edge){to,hd[fr],w},hd[fr]=S;
}

int v[N],sz[N],mx[N];
int n,cnt,rt;
int a[N];
double ans=1e200,ap,na,d[N];

void dfs(int k,int fa){
	sz[k]=1,mx[k]=0;
	fore(k) nfa nvs{
		dfs(_to,k);
		sz[k]+=sz[_to];
		mx[k]=max(mx[k],sz[_to]);
	}
	mx[k]=max(mx[k],cnt-sz[k]);
	if(mx[k]<=(cnt>>1)&&rt==0)rt=k;
}

void calc(int k,int fa,int r,int ds){
	na+=pow(ds,1.5)*a[k];
	d[r]+=1.5*pow(ds,0.5)*a[k];
	fore(k)nfa
		calc(_to,k,r,ds+e[i].w);
}

void solve(int k){
	rt=0;dfs(k,0);k=rt;dfs(k,0);
	if(v[k])return ;
	v[k]=1;
	double sd=0;
	na=0;
	fore(k){
		d[_to]=0;
		calc(_to,k,_to,e[i].w);
		sd+=d[_to];
	}
	if(na<ans)
		ans=na,ap=k;
	fore(k) nvs 
		if(sd-2*d[_to]<0){
			cnt=sz[_to];
			solve(_to);break;
		}
	
}

main(){
	cin>>n;
	mx[0]=1e8;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
	}
	cnt=n;
	solve(1);
	cout<<ap<<' '<<setprecision(12)<<ans<<endl;
}