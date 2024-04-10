/******************
*  Writer: Oh no  *
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

string s;

int dis[30],prev[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	memset(dis,-1,sizeof(dis));
	memset(prev,-1,sizeof(prev));
	
	for(int i=0;i<s.size();i++){
		if(i-prev[s[i]-'a']>dis[s[i]-'a']){
			dis[s[i]-'a']=i-prev[s[i]-'a'];
		}
		prev[s[i]-'a']=i;
	}
	int ans=1e9;
	for(int i=0;i<26;i++){
		dis[i]=max(dis[i],(int)(s.size()-prev[i]));
		ans=min(ans,dis[i]);
	}
	cout<<ans<<endl;
	return 0;
}