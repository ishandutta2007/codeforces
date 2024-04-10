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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,k;
	sc(n,k);
	set<int> cnt;
	int deq[n+1];
	int l=0,r=-1;
	int in;
	rep(i,0,n){
		sc(in);
		if(!cnt.count(in)){
			if(r-l+1==k){
				cnt.erase(deq[l]);
				l++;
				deq[++r]=in;
				cnt.insert(in);
			}
			else{
				deq[++r]=in;
				cnt.insert(in);
			}
		}
	}
	prl(r-l+1);
	for(int i=r;i>=l;i--){
		pr(deq[i],"");
	}
    return 0;
}