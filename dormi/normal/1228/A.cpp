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
bool check(string a){
	set<char> cnt;
	for(char x:a){
		if(cnt.count(x))return false;
		cnt.insert(x);
	}
	return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int l,r;
	sc(l,r);
	rep(i,l,r+1){
		if(check(to_string(i))){
			prl(i);
			return 0;
		}
	}
	prl("-1");
    return 0;
}