#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> >e;
const int N=5+1e6;
bool vis[N];
int prime[N],top_prime=0;
void Euler(int n){
	for(int i=2;i<=n;++i) vis[i]=1;
	for(int i=2;i<=n;++i){
		if(vis[i]) prime[++top_prime]=i;
		for(int j=1;j<=top_prime&&i*prime[j]<=n;++j){
			vis[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	Euler(1e6);
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i) e.push_back(make_pair(i,i+1));
	e.push_back(make_pair(n,1));
//	printf("<%d>",vis[e.size()]);
	for(int i=1;!vis[e.size()];i+=4){
		e.push_back(make_pair(i,i+2));
		if(vis[e.size()]) break;
		e.push_back(make_pair(i+1,i+3));
		if(vis[e.size()]) break;
	}
	printf("%d\n",(int)e.size());
	for(auto i:e) printf("%d %d\n",i.first,i.second);
	return 0;
}