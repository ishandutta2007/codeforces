#include<bits/stdc++.h>
const int N=500050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S,in[to]++;
}

int t,n,k,x,nw,pr,i,ans;
priority_queue<int,vector<int>,greater<int> > q,p;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,nw=0;
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++)
				cin>>x,add(x,i);
		} 
		for(int i=1;i<=n;i++)
			if(!in[i])
				nw++,q.push(i);
		pr=n+1;
		while(q.size()||p.size()){
			if(q.empty()||q.top()<pr)
				while(p.size())q.push(p.top()),p.pop();
			int k=q.top();q.pop();
			if(k<pr)ans++;
			pr=k;
			fore(k){
				in[_to]--;
				if(!in[_to]){
					nw++;
					if(_to>k)q.push(_to);
					else p.push(_to);
				}
			}
		}
		if(nw==n)cout<<ans<<endl;
		else cout<<-1<<endl; 
		for(int i=1;i<=n;i++)in[i]=hd[i]=0;
		S=0;
	}
}