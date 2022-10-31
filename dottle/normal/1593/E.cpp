#include<bits/stdc++.h>
//#define int long long
const int N=1000095;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S,in[to]++;
}

int n,k,x,y,cnt;
queue<int> lf,q;
void del(){
	while(lf.size()){
		cnt--;
		int nw=lf.front();lf.pop();
		fore(nw){
			in[_to]--;
			if(in[_to]==1)q.push(_to);
		} 
	}
	while(q.size())lf.push(q.front()),q.pop();
}

void solve(){
	cin>>n>>k,cnt=n;
	for(int i=1;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
	for(int i=1;i<=n;i++)if(in[i]<=1)lf.push(i);
	for(int i=1;i<=k&&cnt;i++)del();
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)hd[i]=in[i]=0;S=0;
	while(q.size())q.pop();
	while(lf.size())lf.pop();
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
}