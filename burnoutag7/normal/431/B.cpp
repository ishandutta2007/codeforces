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
int g[6][6];
int ans;
int hap(vector<int> v){
	int res=0;
	
	res+=g[v[0]][v[1]]+g[v[1]][v[0]];
	res+=g[v[2]][v[3]]+g[v[3]][v[2]];
	
	res+=g[v[1]][v[2]]+g[v[2]][v[1]];
	res+=g[v[3]][v[4]]+g[v[4]][v[3]];
	
	res+=g[v[2]][v[3]]+g[v[3]][v[2]];
	
	res+=g[v[3]][v[4]]+g[v[4]][v[3]];
	
	return res;
}
int dfs(vector<int> v){
	if(v.size()==5){
		return hap(v);
	}else{
		int res=0;
		for(int i=1;i<=5;i++){
			bool f=0;
			for(int j=0;j<v.size();j++){
				if(v[j]==i){
					f=1;
					break;
				}
			}
			if(!f){
				vector<int> vv;
				for(int j=0;j<v.size();j++){
					vv.push_back(v[j]);
				}
				vv.push_back(i);
				res=max(res,dfs(vv));
			}
		}
		return res;
	}
} 
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cin>>g[i][j];
		}
	}
	vector<int> v;
	ans=dfs(v);
	cout<<ans<<endl;
	return 0;
}