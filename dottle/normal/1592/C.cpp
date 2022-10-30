#include<bits/stdc++.h>
//#define int long long
const int N=500500;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int a[N],n,k,s,fl[N],FL1,FL2;

void dfs(int k,int fa){
	fore(k)if(_to!=fa){
		dfs(_to,k);
		a[k]^=a[_to];
		fl[k]+=fl[_to];
	}
	if(a[k]==0&&fl[k])FL1=1;
	if(a[k]==0&&s==0)FL2=1;
	if(fl[k]>=2)FL1=1;
	if(a[k]==s)fl[k]=max(1,fl[k]);
}

void solve(){
	cin>>n>>k;s=0;
	for(int i=1;i<=n;i++)cin>>a[i],s^=a[i];
	for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
	dfs(1,0);	
	if(k>2&&FL1)cout<<"yes"<<endl;
	else if(k>1&&FL2)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	for(int i=1;i<=n;i++)hd[i]=a[i]=fl[i]=0,FL1=0,FL2=0;
	S=0;
}

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}