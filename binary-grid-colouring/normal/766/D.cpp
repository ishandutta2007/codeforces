#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=2e5+7; 
map<string,int>mp;
int fa[2*maxn];
int n;
void init()
{
	for(int i=0;i<=n;i++){
		fa[i]=i; fa[i+n]=i+n;
	}
}
int find(int x)
{
	return fa[x]==x ? fa[x] : fa[x] = find(fa[x]);
}
int main()
{
	int m,q;
	string s;
	cin>>n>>m>>q;
	init();
	mp.clear();
	for(int i=1;i<=n;i++){
		cin>>s;
		mp[s] = i;
	}
	int op;
	string a,b;
	for(int i=1;i<=m;i++){
		cin>>op>>a>>b;
		int x=mp[a];
		int y=mp[b];
		if(op==1){ // 
			if(find(x) == find(y + n)){
				puts("NO");
			}
			else{
				puts("YES");
				fa[find(y)] = find(x);
				fa[find(y + n)] = find(x + n);
			}
		}
		else if(op==2){ // 
			if(find(x) == find(y)){
				puts("NO");
			}
			else{
				puts("YES"); 
				fa[find(y)] = find(x + n);
				fa[find(y + n)] =find(x);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int x=mp[a];
		int y=mp[b];
		int fa=find(x);
		int fb=find(y);
		if(fa==fb){ // 
			puts("1");
		} 
		else if(find(x+n)==find(y)){ // 
			puts("2");
		}
		else puts("3");
	}
	return 0;
}