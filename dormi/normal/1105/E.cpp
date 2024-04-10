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
	int n,m;
	sc(n,m);
	bitset<40> bad[m];
	lli ma=((lli)1<<(lli)m)-1;
	rep(i,0,m)bad[i]=ma;
	int in;
	string na;
	set<int> peeps;
	int cnt=0;
	map<string,int> conver;
	rep(i,0,n){
		sc(in);
		if(in==1){
			bitset<40> te=ma;
			for(int x:peeps){
				te[x]=false;
			}
			for(int x:peeps){
				te[x]=true;
				bad[x]&=te;
				te[x]=false;
			}
			peeps.clear();
		}
		else{
			sc(na);
			if(!conver.count(na)) {
				conver[na]=cnt++;
			}
			peeps.insert(conver[na]);
		}
	}
	bitset<40> te=ma;
	for(int x:peeps){
		te[x]=false;
	}
	for(int x:peeps){
		te[x]=true;
		bad[x]&=te;
		te[x]=false;
	}
	peeps.clear();
	int half=m/2;
	pair<bool,bitset<40>> dp[1<<half];
	dp[0]={1,ma};
	int bitsz[(1<<half)];
	bitsz[0]=0;
	rep(i,1,1<<half) {
		int lastbit = (i & -i);
		if (dp[i - lastbit].first && dp[i - lastbit].second[(int) log2(lastbit)]) {
			dp[i] = {1, dp[i - lastbit].second & bad[(int) log2(lastbit)]};
			bitsz[i] = __builtin_popcount(i);
		}
		else {
			dp[i] = {0, ma};
			bitsz[i]=0;
		}
	}
	rep(i,0,half) {
		rep(j, 0, 1 << half) {
			if(j&(1<<i))bitsz[j]=max(bitsz[j],bitsz[j^(1<<i)]);
		}
	}
	int ans=bitsz[(1<<half)-1];
	int oth=m-half;
	pair<bool,bitset<40>> dp2[1<<oth];
	dp2[0]={1,ma};
	rep(i,1,((lli)1<<oth)){
		int lastbit = (i & -i);
		int trulastbit=log2(lastbit)+half;
		if (dp2[i - lastbit].first && dp2[i - lastbit].second[trulastbit]) {
			dp2[i] = {1, dp2[i - lastbit].second & bad[trulastbit]};
			ans=max(ans,__builtin_popcount(i)+bitsz[((lli)dp2[i].second.to_ullong())%((lli)1<<(lli)half)]);
		}
		else dp2[i] = {0, ma};
	}
	prl(ans);
    return 0;
}