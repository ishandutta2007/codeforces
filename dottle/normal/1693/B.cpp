#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,l[N],r[N];
int v[N],rs;

void dfs(int k,int fa){
	v[k]=0;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		v[k]+=v[_to];
	}
	if(v[k]<l[k])rs++,v[k]=r[k];
	v[k]=min(v[k],r[k]);
}

void solve(){
	cin>>n;
	rs=0;
	for(int i=1;i<=n;i++)hd[i]=0,S=0;
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		add(i,x),add(x,i);
	}
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	dfs(1,0);
	cout<<rs<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}