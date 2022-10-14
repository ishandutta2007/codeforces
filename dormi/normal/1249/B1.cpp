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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int q;
	sc(q);
	while(q--){
		int n;
		sc(n);
		int to[n+1];
		bool done[n+1];
		int ans[n+1];
		vector<int> cyc;
		rep(i,1,n+1){
			sc(to[i]);
			done[i]=false;
		}
		rep(i,1,n+1){
			if(!done[i]){
				cyc.clear();
				int cur=to[i];
				cyc.push_back(i);
				while(cur!=i){
					cyc.push_back(cur);
					cur=to[cur];
				}
				for(int x:cyc){
					done[x]=true;
					ans[x]=sz(cyc);
				}
			}
		}
		rep(i,1,n+1){
			pr(ans[i],"");
		}
		prl("");
	}
    return 0;
}