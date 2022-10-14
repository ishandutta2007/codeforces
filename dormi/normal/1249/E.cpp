#include <bits/stdc++.h>
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
lli dist[(int)2e5+1][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	lli c;
	sc(n,c);
	lli st[n],el[n];
	rep(i,0,n)dist[i][0]=LLONG_MAX,dist[i][1]=LLONG_MAX;
	rep(i,0,n-1)sc(st[i]);
	rep(i,0,n-1)sc(el[i]);
	priority_queue<pair<lli,pair<int,int>>,vector<pair<lli,pair<int,int>>>,greater<pair<lli,pair<int,int>>>> q;
	dist[0][0]=0;
	q.push({0,{0,0}});
	while(sz(q)){
		auto cur=q.top();
		q.pop();
		if(cur.first<=dist[cur.second.first][cur.second.second]){
			lli te=cur.first+st[cur.second.first];
			if(te<dist[cur.second.first+1][0]){
				dist[cur.second.first+1][0]=te;
				q.push({te,{cur.second.first+1,0}});
			}
			te=cur.first+el[cur.second.first]+(cur.second.second?0:c);
			if(te<dist[cur.second.first+1][1]){
				dist[cur.second.first+1][1]=te;
				q.push({te,{cur.second.first+1,1}});
			}
		}
	}
	rep(i,0,n){
		pr(min(dist[i][0],dist[i][1]),"");
	}
    return 0;
}