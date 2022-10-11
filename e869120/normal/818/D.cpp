#include<bits/stdc++.h>
using namespace std;
long long n,A,a[100009],v[1000009],c,s[1000009];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
int main(){
	cin>>n>>A;
	for(int i=1;i<=1000000;i++){
		if(i==A)continue;
		Q.push(make_pair(0,i));
		s[i]++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==A)c++;
		else {
			if(s[a[i]]==0)continue;
			v[a[i]]++;
			Q.push(make_pair(v[a[i]],a[i]));
			s[a[i]]++;
		}
		while(!Q.empty()){
			if(c>Q.top().first){s[Q.top().second]--;Q.pop();}
			else break;
		}
	}
	for(int i=1;i<=1000000;i++){
		if(s[i]>=1){cout<<i<<endl;return 0;}
	}
	cout<<"-1"<<endl;
	return 0;
}