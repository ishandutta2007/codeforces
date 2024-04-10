#include <bits/stdc++.h>
using namespace std;
const long long INF  = 1e18;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
set<pair<int,int> >vis;
set<pair<int,pair<int,int> > >Q,tmp;
int main(){
	int X = 0, Y = 0;
	int cur = 0;
	int n,t;
	cin >> n;
	cin >> t;
	for(int i = 0; i < t; i++){
		vis.insert(make_pair(X + i * dx[cur], Y + i * dy[cur]));
	}
	Q.insert(make_pair(cur,make_pair(X, Y + t - 1)));
	n--;
	while(n--){
		cin >> t;
		tmp.clear();
		for(auto x:Q){
			cur = x.first;
			int d1 = (cur + 1) % 8;
			int d2 = (cur + 7) % 8;
			X=x.second.first;
			Y=x.second.second;
			for(int i = 1; i <= t; i++){
				vis.insert(make_pair(X + i * dx[d1], Y + i * dy[d1]));
				vis.insert(make_pair(X + i * dx[d2], Y + i * dy[d2]));
			}
			tmp.insert(make_pair(d1,make_pair(X + t * dx[d1], Y + t * dy[d1])));
			tmp.insert(make_pair(d2,make_pair(X + t * dx[d2], Y + t * dy[d2])));
		}
		Q.clear();
		Q=tmp;
	}
	cout << vis.size() << endl;
	//system("pause");
	return 0;
}