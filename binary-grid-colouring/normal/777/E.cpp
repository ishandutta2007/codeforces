#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>>V;
int main()
{
	int n;
	cin>>n;
	int a,b,h;
	for(int i = 0; i < n; i++){
		cin>>a>>b>>h;
		V.push_back(make_pair(make_pair(b,a),h));
	}
	sort(V.rbegin(),V.rend());// 
	/* 
	for(auto t : V){
		cout<<t.first.second<<" ";
		cout<<t.first.first<<" ";
		cout<<t.second<<endl;
	}
	*/
	long long ans=0;
	priority_queue<pair<long long,int>>pq;
	for(auto t : V)
	{
		int x = t.first.second;
		int y = t.first.first;
		int z = t.second;
		while(!pq.empty() && pq.top().second >= y){
			pq.pop();
		}
		long long res=0;
		if(pq.empty()){
			res = z;
		}
		else res = z + pq.top().first;
		
		ans = max(ans,res);
		pq.push(make_pair(res,x));
	}
	cout<<ans<<endl;
	return 0;
}