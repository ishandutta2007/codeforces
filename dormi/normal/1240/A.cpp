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
lli gcd(lli a, lli b){
	if(a==0)return b;
	return gcd(b%a,a);
}
lli k;
lli x,y;
lli a,b;
vector<lli> ams;
lli oth;
bool work(lli tickets){
	lli am=tickets/oth;
	lli ans=0;
	lli aam=tickets/a-am;
	lli bam=tickets/b-am;
	if(am)ans+=ams[am]/100*(x+y);
	if(aam)ans+=(ams[am+aam]-ams[am])/100*(x);
	if(bam)ans+=(ams[am+aam+bam]-ams[am+aam])/100*(y);
	return ans>=k;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	sc(q);
	while(q--){
		int n;
		sc(n);
		int in;
		ams.clear();
		rep(i,0,n){
			sc(in);
			ams.push_back(in);
		}
		ams.push_back(LLONG_MAX);
		sort(ams.begin(),ams.end(),greater<lli>());
		ams[0]=0;
		rep(i,1,n+1)ams[i]+=ams[i-1];
		sc(x,a,y,b);
		oth=a*b/gcd(a,b);
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		sc(k);
		lli lo=0;
		lli hi=n;
		while(lo!=hi){
			lli mid=(lo+hi)/2;
			if(work(mid))hi=mid;
			else lo=mid+1;
		}
		if(!work(lo))prl("-1");
		else prl(lo);
	}
	return 0;
}