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
set<int> t;
int n,m,a[15],e;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>e;
		a[e]++;
	}
	int ans=0;
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			ans+=a[i]*a[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}