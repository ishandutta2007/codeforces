#include<bits/stdc++.h>
const int N=1000050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int t,n,b[N],ans;
void clr(){
	S=0;
	for(int i=1;i<=n;i++)hd[i]=b[i]=0;
}

void dfs(int k,int f){
	fore(k)if(_to!=f)
		dfs(_to,k),b[k]|=!b[_to];
	ans-=b[k]*2;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n,ans=n;
		for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
		dfs(1,0); 
		if(b[1])ans++;
		cout<<ans<<endl;
		clr();
	}
}