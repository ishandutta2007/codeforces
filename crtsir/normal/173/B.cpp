#include<bits/stdc++.h>
using namespace std;
vector<int>v[2003];//MIAO
int n,m,ans[2003];
char c;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>c;
			if(c-'.')
				v[i].push_back(j+n),
				v[j+n].push_back(i);
		}
	queue<int>q;
	q.push(0);
	ans[0]=1;
	while(!q.empty()){
		for(int i=0;i<v[q.front()].size();i++)
			if(!ans[v[q.front()][i]])
				ans[v[q.front()][i]]=ans[q.front()]+1,
				q.push(v[q.front()][i]);
		q.pop();
	}
	if(ans[n-1])
		cout<<ans[n-1]-1;
	else
		cout<<-1;
}