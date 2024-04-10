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
int n,m,t,cnt;
vector<int> v;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;m>0;i--){
		m-=v[i];
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}