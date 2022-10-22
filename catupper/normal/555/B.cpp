#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;

Int n, m;
Int l[216000], r[216000];
Int ll[216000], rr[216000];
Int a[216000];
Int ans[216000];
Int cnt;
vector<P> poInts;
vector<P> bridge;
priority_queue<P, vector<P>, greater<P> > q;
int main(){
	cin >> n >> m;
	for(Int i = 0;i < n;i++){
		cin >> l[i] >> r[i];
		if(i){
			ll[i-1] = l[i] - r[i-1];
			rr[i-1] = r[i] - l[i-1];
			poInts.push_back(P(ll[i-1], i-1));
		}
	}                                         
	sort(poInts.begin(), poInts.end());
	for(Int i = 0;i < m;i++){
		cin >> a[i];
		bridge.push_back(P(a[i], i+1));
	}
	sort(bridge.begin(), bridge.end());
	Int p = 0;
	for(Int i = 0;i < m;i++){
		Int ind = bridge[i].second;
		Int d = bridge[i].first;
		while(p < n-1 && poInts[p].first <= d){
			Int ii = poInts[p].second;
			q.push(P(rr[ii], ii));
			p++;
		}
		while(!q.empty() && q.top().first < d){
			q.pop();
		}
		if(q.empty())continue;		
		P tmp = q.top();q.pop();
		ans[tmp.second] = ind;
		cnt++;
	}
	if(cnt == n-1){
		cout << "Yes" << endl;
		for(Int i = 0;i < n-1;i++){
			if(i)cout << " " ;
			cout << ans[i];
		}                     cout << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
	
}