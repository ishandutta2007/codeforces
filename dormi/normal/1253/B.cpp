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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	set<int> entered;
	set<int> cur;
	int in;
	bool work=true;
	vector<int> empties;
	empties.push_back(0);
	rep(i,1,n+1){
		sc(in);
		if(in<0) {
			in=abs(in);
			if(!cur.count(in))work = false;
			else cur.erase(in);
		}
		else{
			if(entered.count(in)){
				work=false;
			}
			else{
				cur.insert(in);
				entered.insert(in);
			}
		}
		if(sz(cur)==0){
			empties.push_back(i);
			entered.clear();
		}
	}
	if(!work||empties[sz(empties)-1]!=n){
		prl("-1");return 0;
	}
	else{
		prl(sz(empties)-1);
		rep(i,1,sz(empties)){
			pr(empties[i]-empties[i-1],"");
		}
	}
    return 0;
}