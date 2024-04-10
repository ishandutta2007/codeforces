/******************
*  Author: BD747  *
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
#include<bits/stdc++.h>
using namespace std;

#define MP make_pair

int n;
int a[1005];
int ave;
int ans;
vector<pair<int,int> > v;

void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=min( abs(a[i]-ave) , min( abs(a[i]-ave-1) , abs(a[i]-ave+1) ) );
	}
	v.push_back(MP(ans,ave));
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=100;i++){
		ave=i;
		solve();
	}
	sort(v.begin(),v.end());
	cout<<v[0].second<<' '<<v[0].first<<endl;

	return 0;
}