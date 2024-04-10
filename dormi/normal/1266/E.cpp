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
const int MAXN=2e5+1;
lli goal[MAXN];
lli ams[MAXN];
map<lli,int> milestones[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    lli turns=0;
    rep(i,1,n+1){
        sc(goal[i]);
        turns+=goal[i];
    }
    int q;
    sc(q);
    int s,u;
    lli t;
    while(q--){
		sc(s,t,u);
		if(milestones[s].count(t)){
			ams[milestones[s][t]]-=1;
			if(ams[milestones[s][t]]<goal[milestones[s][t]])turns++;
			milestones[s].erase(t);
		}
		if(u){
			milestones[s][t]=u;
			ams[milestones[s][t]]+=1;
			if(ams[milestones[s][t]]<=goal[milestones[s][t]])turns--;
		}
		prl(turns);
    }
    return 0;
}