#include<bits/stdc++.h>
//#define int long long
const int N=1<<22;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

void solve(){
	int n;cin>>n;
	vector<int> v(1<<n),vis(1<<n),u(1<<n),iv(1<<n),nw,nx,id(1<<n);
	fill(hd,hd+(1<<n),0);S=0;
	for(int i=0,x,y;i<n*(1<<n-1);i++)
		cin>>x>>y,add(x,y),add(y,x);
	queue<int> q;
	q.push(0);
	v[0]=0,u[0]=1;
	int cnt=1;
	vis[0]=2;
	int p=1;
	fore(0)
		vis[_to]=1,nw.push_back(_to),id[_to]=p,++cnt,p<<=1;
	while(cnt<1<<n){
		nx.clear();
		for(int i:nw)vis[i]=2;
		for(int x:nw)
			fore(x)
				if(vis[_to]!=2){
					id[_to]|=id[x];
					if(!vis[_to])
						vis[_to]=1,++cnt,nx.push_back(_to);
				}
		nw=nx;
	}
	for(int i=0;i<1<<n;i++)
		v[id[i]]=i;
	for(int i=0;i<1<<n;i++)
		cout<<v[i]<<' ';
	cout<<endl;
	if(n!=(n&-n))cout<<-1<<endl;
	else{
		for(int i=0;i<1<<n;i++)
			for(int j=0;j<n;j++)
				if((i>>j)&1)
					iv[v[i]]^=j;
		for(int i=0;i<1<<n;i++)
			cout<<iv[i]<<' ';
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}