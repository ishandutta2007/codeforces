#include<bits/stdc++.h>
using namespace std;
 
#define int long long
int val[100002];
int32_t main(){
	int n,m;
	scanf("%lld %lld",&n,&m);
	int u,v,d;
	for(int i=0;i<m;i++){
		scanf("%lld %lld %lld",&u,&v,&d);
		u--,v--;
		val[u]-=d;
		val[v]+=d;
	}
	int id = 0;
	vector<array<int,3>> resp;
	for(int i=0;i<n;i++){
		while(val[i]>0){
			while(val[id]>=0) id++;
			int mi = min(val[i],-val[id]);
			val[i]-=mi;
			val[id]+=mi;
			resp.push_back({id+1,i+1,mi});
			//cout << i << " " << id << " " << mi << '\n';
		}
	}
	printf("%lld\n",(int)resp.size());
	for(auto out:resp)
		printf("%lld %lld %lld\n",out[0],out[1],out[2]);
}