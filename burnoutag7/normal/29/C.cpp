/******************
*  Writer: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> g[100005];
vector<int> out[2];
int n;
bool u[100005];
map<int,int> ftu,utf;//form to use and use to form
int cnt;
int dst,start;
bool f;

bool dfs(int x,int con){
	u[x]=1;
	out[con].push_back(x);
	if(x==dst){
		return true;
	}
	for(int i=0;i<g[x].size();i++){
		if(!u[g[x][i]]){
			return dfs(g[x][i],con);
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		bool fx=0,fy=0;
		if(x==1)fx=1;
		if(y==1)fy=1;
		if(ftu.find(x)!=ftu.end()){
			x=ftu[x];
		}else{
			ftu[x]=++cnt;
			utf[cnt]=x;
			x=ftu[x];
		}
		if(ftu.find(y)!=ftu.end()){
			y=ftu[y];
		}else{
			ftu[y]=++cnt;
			utf[cnt]=y;
			y=ftu[y];
		}
		g[x].push_back(y);
		g[y].push_back(x);
		if(fx==1)dst=x;
		if(fy==1)dst=y;
	}
	
	start=1;
	while(start==dst)start++;
	//cout<<"STARTFROM "<<utf[start]<<endl;
	
	if(g[start].size()>1){//cout<<"CON 1"<<endl;
		f=dfs(start,0);
		dfs(start,1);
		if(f){//cout<<"CON 1"<<endl;
			for(int i=out[1].size()-1;i>=0;i--){
				cout<<utf[out[1][i]]<<' ';
			}
			for(int i=1;i<out[0].size();i++){
				cout<<utf[out[0][i]]<<' ';
			}
		}else{//cout<<"CON 2"<<endl;
			for(int i=out[0].size()-1;i>=0;i--){
				cout<<utf[out[0][i]]<<' ';
			}
			for(int i=1;i<out[1].size();i++){
				cout<<utf[out[1][i]]<<' ';
			}
		}
	}else{//cout<<"CON 2"<<endl;
		dfs(start,0);
		for(int i=0;i<out[0].size();i++){
			cout<<utf[out[0][i]]<<' ';
		}
	}
	
	return 0;
}