#include<bits/stdc++.h>
using namespace std;
int n,a[103][103];
vector<pair<int,int> >v[3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if((i+j)&1)v[1].push_back(make_pair(i,j));else v[2].push_back(make_pair(i,j));
	while(!v[1].empty()&&!v[2].empty()){
		int x;cin>>x;
		if(x==1||x==3){
			pair<int,int> p=v[2].back();
			a[p.first][p.second]=2;
			fflush(stdout);
			cout<<"2 "<<p.first<<" "<<p.second<<"\n";
			fflush(stdout);
			v[2].pop_back();
		}else{
			pair<int,int> p=v[1].back();
			a[p.first][p.second]=1;
			fflush(stdout);
			cout<<"1 "<<p.first<<" "<<p.second<<"\n";
			fflush(stdout);
			v[1].pop_back();
		}
	}
	int tmp,t;
	if(v[1].empty())tmp=1,t=2;
	else tmp=2,t=1;
	while(!v[t].empty()){
		pair<int,int> p=v[t].back();
		int x;cin>>x;
		fflush(stdout);
		if(x==tmp)cout<<t<<" ";
		else cout<<6-tmp-x<<" ";
		cout<<p.first<<" "<<p.second<<"\n";
		fflush(stdout);
		v[t].pop_back();
	}
}