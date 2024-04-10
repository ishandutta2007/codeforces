#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int degree[maxn];

double s;

int main(){
	cin>>n>>s;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		degree[u]++;
		degree[v]++;
	}
	if(n==2){
		printf("%.20lf",s);
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(degree[i]==1) cnt++;
	}
	printf("%.20lf",(s/(double)(cnt))*2.00);
	return 0;
}