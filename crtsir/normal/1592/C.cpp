#include<bits/stdc++.h>
using namespace std;
vector<int>v[100003]; 
int T,n,k,a[100003],b[100003],fa[100003];
void dfs(int x,int p){b[x]=a[x];
	fa[x]=p;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			dfs(v[x][i],x),
			b[x]^=b[v[x][i]];
}
void del(int x,int y){
	vector<int>tmp;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=y)
			tmp.push_back(v[x][i]);
	v[x]=tmp;tmp.clear();
	for(int i=0;i<v[y].size();i++)
		if(v[y][i]!=x)
			tmp.push_back(v[y][i]);v[y]=tmp;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;int qaq=0;
		for(int i=0;i<n;i++)
			scanf("%d",a+i),
			v[i].clear(),
			qaq^=a[i];
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(0,-1);
		bool ok=0;
		if(qaq==0)
			ok=1;
		else{
			for(int i=1;i<n;i++)
				if(b[i]==qaq){
					del(fa[i],i);
					dfs(0,-1);
					dfs(i,-1);
					for(int j=1;j<n;j++)
						if(i!=j&&b[j]==qaq)
							ok=1;
					break;
				}
			if(k==2)ok=0;
		}
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}