#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
vector<int>G[300001];
set<int>S[300001];
int dist[300000],ct[300000];
inline void Solve(){
	int n,m,x,y,tot=0;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		vector<int>().swap(G[i]);
	}
	map<int,int>C;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		C[x]++;
	}
	for(auto T:C){
		dist[tot]=T.first;
		ct[tot]=T.second;
		G[T.second].push_back(tot);
		tot++;
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		x=lower_bound(dist,dist+tot,x)-dist;
		y=lower_bound(dist,dist+tot,y)-dist;
		S[x].insert(y);
		S[y].insert(x);
	}
	vector<int>A;
	for(int i=1;i<=n;i++){
		if(G[i].empty()==false){
			A.push_back(i);
			sort(G[i].begin(),G[i].end());
		}
	}
	L ans=0;
	for(int i=0;i!=tot;i++){
		S[i].insert(i);
		for(int T:A){
			for(auto T2=G[T].rbegin();T2!=G[T].rend();T2++){
				if(S[i].count(*T2)==0){
					L c=(L)(ct[i]+ct[*T2])*(dist[i]+dist[*T2]);
					if(c>ans){
						ans=c;
					}
					break;
				}
			}
		}
	}
	printf("%lld\n",ans);
	for(R i=0;i!=tot;i++){
		set<int>().swap(S[i]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}