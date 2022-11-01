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
vector<int> a[110];
int f[110],ans;
int fi(int x){
	if(x==f[x]){
		return x;
	}else{
		return f[x]=fi(f[x]);
	}
}
void jo(int x,int y){
	int u=fi(x),v=fi(y);
	if (u!=v){
		ans--;
		f[u]=v;
	}
}
int main(){
	int i,j,k,m,n,x,y,z;
	bool flag=0;
	cin>>n>>m;
	for (i=1;i<=n;i++){
		cin>>k;
		if (k) flag=1;
		while (k--){
			cin>>x;
			a[x].push_back(i);
		}
	}
	if (!flag){
		cout<<n;
		return 0;
	}
	for (i=1;i<=n;i++)
		f[i]=i;
	ans=n;
	for (i=1;i<=m;i++){
		for (j=1;j<a[i].size();j++){
			jo(a[i][j-1],a[i][j]);
		}
	}
	cout<<ans-1;
	return 0;
}