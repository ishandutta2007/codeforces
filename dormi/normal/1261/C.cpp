#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int xc[8]={0,0,1,-1,1,-1,1,-1};
int yc[8]={1,-1,0,0,1,-1,-1,1};
vector<vector<char>> arr;
vector<vector<int>> dist;
vector<vector<bool>> gone;
vector<vector<bool>> gone2;
int n,m;
queue<pair<int,pii>> q;
queue<pii> qu;
vector<pair<int,pii>> th;
bool work(int dist){
	int loc=0;
	int goneto=0;
	for(auto x:th)gone2[x.second.first][x.second.second]=false;
	while(loc<sz(th)&&th[loc].first>=dist){
		q.push({0,th[loc].second});
		gone2[th[loc].second.first][th[loc].second.second]=true;
		loc++;
	}
	while(sz(q)){
		auto cur=q.front();
		q.pop();
		goneto+=1;
		if(cur.first+1>=dist)continue;
		rep(i,0,8) {
			pii ne = {cur.second.first + xc[i], cur.second.second + yc[i]};
			if(ne.first>=0&&ne.first<=n+1&&ne.second>=0&&ne.second<=m+1) {
				if (arr[ne.first][ne.second] == 'X' && !gone2[ne.first][ne.second]) {
					gone2[ne.first][ne.second] = true;
					q.push({cur.first+1,ne});
				}
			}
		}
	}
	if(goneto==sz(th))return true;
	return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
	sc(n,m);
	arr.resize(n+2);
	dist.resize(n+2);
	gone.resize(n+2);
	gone2.resize(n+2);
	rep(i,0,n+2)arr[i].resize(m+2,'.'),dist[i].resize(m+2,-1),gone2[i].resize(m+2,false),gone[i].resize(m+2,false);
	rep(i,1,n+1){
		rep(j,1,m+1)sc(arr[i][j]);
	}
	rep(i,0,n+2)rep(j,0,m+2){
		if(arr[i][j]=='.'){
			dist[i][j]=0;
			q.push({0,{i,j}});
		}
	}
	while(sz(q)){
		auto cur=q.front();
		q.pop();
		rep(i,0,8){
			pii ne={cur.second.first+xc[i],cur.second.second+yc[i]};
			if(ne.first>=0&&ne.first<=n+1&&ne.second>=0&&ne.second<=m+1){
				if(dist[ne.first][ne.second]==-1){
					dist[ne.first][ne.second]=cur.first+1;
					q.push({cur.first+1,ne});
				}
			}
		}
	}
	int time=INT_MAX;
	rep(i,0,n+2)rep(j,0,m+2){
		if(arr[i][j]=='X'&&!gone[i][j]){
			qu.push({i,j});
			th.clear();
			gone[i][j]=true;
			while(sz(qu)){
				auto cur=qu.front();
				qu.pop();
				th.push_back({dist[cur.first][cur.second],cur});
				rep(i,0,8) {
					pii ne = {cur.first + xc[i], cur.second + yc[i]};
					if(ne.first>=0&&ne.first<=n+1&&ne.second>=0&&ne.second<=m+1) {
						if (arr[ne.first][ne.second] == 'X' && !gone[ne.first][ne.second]) {
							gone[ne.first][ne.second] = true;
							qu.push(ne);
						}
					}
				}
			}
			sort(th.begin(),th.end(),greater<pair<int,pii>>());
			int lo=1;
			int hi=max(m,n);
			while(lo!=hi){
				int mid=(lo+hi)/2+1;
				if(work(mid))lo=mid;
				else hi=mid-1;
			}
			time=min(time,lo);
		}
	}
	prl(time-1);
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(dist[i][j]>=time){
				pr('X');
			}
			else pr('.');
		}
		prl("");
	}
    return 0;
}
/*
7 5
XXX..
XXX..
XXX..
..X..
..XXX
..XXX
..XXX
 */