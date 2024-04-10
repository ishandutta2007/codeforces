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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int which[MAXN];
bool work=true;
int cnt[4];
void dfs(int loc){
	set<int> can;
	can.insert(1);
	can.insert(2);
	can.insert(3);
	for(int x:matrix[loc]){
		if(can.count(which[x]))can.erase(which[x]);
	}
	if(can.empty()){
		work=false;
		return;
	}
	which[loc]=*can.begin();
	cnt[*can.begin()]++;
	for(int x:matrix[loc]){
		if(!which[x]){
			dfs(x);
			if(!work)return;
		}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	int a,b;
	rep(i,0,m){
		sc(a,b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	rep(i,1,n+1) {
		if (!which[i]){
			dfs(i);
			if(!work){
				prl("-1");
				return 0;
			}
		}
	}
	if(work){
		if(cnt[1]==0||cnt[2]==0||cnt[3]==0){
			prl("-1");
			return 0;
		}
		rep(i,1,n+1){
			if((int)matrix[i].size()+cnt[which[i]]!=n){
				prl(-1);
				return 0;
			}
		}
		rep(i,1,n+1){
			pr(which[i],"");
		}
	}
	else prl(-1);
	return 0;
}