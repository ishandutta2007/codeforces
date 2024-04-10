#include <bits/stdc++.h>
using namespace std;
int dist[2001],a[1001],n,k;queue<int>Q;
int main() {
	cin>>n>>k;
	for(int i=0;i<k;i++){int r;scanf("%d",&r);a[r]=1;}
	for(int i=0;i<=2000;i++)dist[i]=1e9;dist[1000]=0;Q.push(1000);
	while(!Q.empty()){
		int a1=Q.front();Q.pop();
		for(int i=0;i<=1000;i++){
			if(a[i]==0)continue;
			int v=a1+i-n;if(v<0 || v>2000)continue;
			if(dist[v]>dist[a1]+1 || dist[v]==0){
				dist[v]=dist[a1]+1;Q.push(v);
			}
		}
	}
	if(dist[1000]>=1e8 || dist[1000]==0)dist[1000]=-1;
	cout<<dist[1000]<<endl;
	return 0;
}