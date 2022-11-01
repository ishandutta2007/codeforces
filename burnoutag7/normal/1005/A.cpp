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
int n,las,cur,ans;
vector<int> v;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cur;
		if(cur<=las){
			ans++;
			v.push_back(las);
		}
		las=cur;
	}
	v.push_back(las);
	cout<<ans+1<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<' ';
	}
	return 0;
}