#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int T,n,k,a[1003];
bool vis[1003];
vector<int>g;
string calc(vector<int>v){
	cout<<"? "<<v.size()<<' '<<v.size()<<'\n';
	for(int i=0;i<v.size();i++)cout<<v[i]+1<<' ';cout<<'\n';
	for(int i=0;i<v.size();i++)cout<<g[i]+1<<' ';cout<<'\n';
	fflush(stdout);string s;cin>>s;return s;
}
void solve(int l,int r){
	if(l==r-1){
		cout<<"! "<<a[l]+1<<'\n';
		fflush(stdout);
		return;
	}vector<int>h;
	if(r-l>g.size()){
		for(int i=l;i<l+g.size();i++)
			h.push_back(a[i]);
		if(calc(h)=="EQUAL"){
			for(int i=0;i<h.size();i++)
				g.push_back(h[i]);
			solve(l+h.size(),r);
		}else
			solve(l,l+h.size());
	}else{
		for(int i=l;i<l+(r-l)/2;i++)
			h.push_back(a[i]);
		if(calc(h)=="EQUAL")
			solve(l+(r-l)/2,r);
		else
			solve(l,l+(r-l)/2);
	}
}
int main(){
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		memset(vis,0,sizeof(vis));
		int nw=rng()%n,cs=min(n-1,32),tmp;
		g.clear();g.push_back(nw);vis[nw]=1;
		while(cs){
			tmp=rng()%n;if(vis[tmp])continue;
			if(calc({tmp})=="FIRST")nw=tmp,g[0]=nw;vis[tmp]=1;cs--;
		}for(int i=0,m=0;i<n;i++)
			if(nw!=i)a[m++]=i;n--;solve(0,n);
	}
}