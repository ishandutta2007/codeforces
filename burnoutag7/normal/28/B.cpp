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

int f[105];

int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
}

int n;
int a[105];
int d;

vector<int> v1[105],v2[105];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		f[i]=i;
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>d;
		if(i-d>0){
			unite(i,i-d);
		}
		if(i+d<=n){
			unite(i+d,i);
		}
	}
	
	for(int i=1;i<=n;i++){
		v1[find(i)].push_back(a[i]);
		v2[find(i)].push_back(i);
	}
	
	for(int i=1;i<=n;i++){
		if(find(i) != i) continue;
		sort(v1[i].begin(),v1[i].end());
		sort(v2[i].begin(),v2[i].end());
		for(int j=0;j<v1[i].size();j++){
			if(v1[i][j] != v2[i][j]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"YES"<<endl;

	return 0;
}