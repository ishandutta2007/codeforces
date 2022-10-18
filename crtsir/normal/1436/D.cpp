#include<bits/stdc++.h>
using namespace std;
int n,a[200003];
long long p[200003],l[200003];
vector<int>v[200003];
void DFS(int x){
	p[x]=a[x];
	l[x]=bool(!v[x].size());
	for(int i=0;i<v[x].size();i++){
		DFS(v[x][i]);
		p[x]+=p[v[x][i]];
		l[x]+=l[v[x][i]];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int P;
		scanf("%d",&P);
		v[P-1].push_back(i);
	}
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	DFS(0);
	long long ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,(p[i]+l[i]-1)/l[i]);
	cout<<ans;
}