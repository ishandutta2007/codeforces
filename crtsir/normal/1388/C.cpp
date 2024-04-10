#include<bits/stdc++.h>
using namespace std;
int T,n,m,p[100003],h[100003],val[100003];
vector<int>v[100003];
bool ok; 
int dfs(int x,int pa){
	int cnt=0;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=pa)
			cnt+=dfs(v[x][i],x);
	if(((h[x]%2)+2)%2!=val[x]%2)ok=0;
	if(fabs(h[x])>val[x])ok=0;
	if((h[x]+val[x])/2<cnt)ok=0;
	return (h[x]+val[x])/2;
}
int calcvalue(int x,int pa){
	val[x]=p[x];
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=pa)
			val[x]+=calcvalue(v[x][i],x);
	return val[x];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)v[i].clear();
		for(int i=0;i<n;i++)scanf("%d",p+i);
		for(int i=0;i<n;i++)scanf("%d",h+i);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}ok=1;
		calcvalue(0,-1);
		dfs(0,-1);
		if(!ok)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}