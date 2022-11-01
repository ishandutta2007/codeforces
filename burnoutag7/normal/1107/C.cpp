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

typedef long long ll;

int n,k;
int a[200005];
ll ans;
string s;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>s;
	for(int i=0;i<n;){
		int j;
		for(j=i+1;j<n&&s[j]==s[i];j++);
		if(j-i<=k){
			for(int kk=i;kk<j;kk++){
				ans+=a[kk];
			}
		}else{
			priority_queue<int> pq;
			for(int kk=i;kk<j;kk++){
				pq.push(a[kk]);
			}
			int clo=k;
			while(clo>0){
				clo--;
				ans+=pq.top();
				pq.pop();
			}
		}
		i=j;
	}
	cout<<ans<<endl;

	return 0;
}