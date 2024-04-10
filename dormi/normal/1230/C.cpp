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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
vector<int> matrix[8];
int wh[8];
int n,m;
int ans=0;
bool done[7][7];
void run(){
	memset(done,false,sizeof(done));
	int cnt=0;
	rep(i,1,n+1){
		for(int x:matrix[i]){
			if(!done[wh[i]][wh[x]]){
				cnt+=1;
				done[wh[i]][wh[x]]=true;
				done[wh[x]][wh[i]]=true;
			}
		}
	}
	ans=max(ans,cnt);
}
void counter(int ind){
	rep(i,1,7){
		wh[ind]=i;
		if(ind==n) run();
		else counter(ind+1);
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m);
    int a,b;
    rep(i,0,m){
    	sc(a,b);
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }
	counter(1);
    prl(ans);
    return 0;
}