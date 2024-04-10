#include<bits/stdc++.h>

using namespace std;

const int maxn=1000005;
const int maxt=100005; 

char x[maxn<<1];
string f[maxt];
int l[maxt];
stack<pair<int,int> > s;
vector<int> v[maxn<<1];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		l[i]=f[i].size();
		int g;cin>>g;
		while(g--){
			int id;
			cin>>id;
			v[id].push_back(i);
		}
	}
	int rp=0;
	for(int i=1;i<(maxn<<1);i++){
		for(int j=0;j<v[i].size();j++){
			s.push(make_pair(i,v[i][j]));
		} 
		while(!s.empty()&&s.top().first+l[s.top().second]-1<i)s.pop();
		if(!s.empty()){
			x[i]=f[s.top().second][i-s.top().first];
			rp=i; 
		} 
	}
	for(int i=1;i<=rp;i++){
		if(x[i]==0)cout<<'a';
		else cout<<x[i];
	}
	return 0;
}