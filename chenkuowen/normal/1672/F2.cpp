#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
vector<int> f[N];
int b[N],a[N];
void add_ring(vector<int> a){
	vector<int> s(a.size());
	for(int i=0;i<a.size();++i){
		s[i]=f[a[i]].back();
		f[a[i]].pop_back();
	}
	for(int i=0;i<a.size();++i)
		b[s[i]]=a[(i+1)%a.size()];
}
bool cmp(int x,int y){ return f[x].size()>f[y].size(); }
vector<int> e[N];
int rd[N];
bool topo(int n){
	queue<int> q;
	for(int i=1;i<=n;++i)
		if(rd[i]==0) q.push(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto y:e[x])
			if((--rd[y])==0) q.push(y);
	}
	for(int i=1;i<=n;++i)
		if(rd[i]>0) return false;
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) f[i].clear(),e[i].clear(),rd[i]=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),f[a[i]].push_back(i);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		vector<int> q;
		for(int i=1;i<=n;++i) 
			if(f[i].size()>0) q.push_back(i);
		sort(q.begin(),q.end(),cmp);
		for(int i=1;i<=n;++i)
			if(a[i]!=q[0]&&b[i]!=q[0]){
				e[a[i]].push_back(b[i]);
				rd[b[i]]++;
			}
		if(topo(n)) puts("AC");
		else puts("WA");
	}
	return 0;
}