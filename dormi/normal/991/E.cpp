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
lli am[10];
lli curam[10];
lli fact[20];
lli recu(int loc){
	if(loc==10){
		lli todiv=1;
		lli tot=0;
		rep(i,0,10){
			todiv*=fact[curam[i]];
			tot+=curam[i];
		}
		lli ans=fact[tot]/todiv;
		if(curam[0]) {
			curam[0]-=1;
			todiv=1;
			tot=0;
			rep(i, 0, 10) {
				todiv *= fact[curam[i]];
				tot += curam[i];
			}
			ans-=fact[tot]/todiv;
			curam[0]+=1;
		}
		return ans;
	}
	lli ans=0;
	if(am[loc]==0)return recu(loc+1);
	rep(i,1,am[loc]+1){
		curam[loc]=i;
		ans+=recu(loc+1);
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fact[0]=1;
    rep(i,1,20){
    	fact[i]=i*fact[i-1];
    }
	string a;
	sc(a);
	for(char x:a){
		am[x-'0']+=1;
	}
	prl(recu(0));
    return 0;
}