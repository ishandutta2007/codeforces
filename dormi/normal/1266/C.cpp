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
	int r,c;
	sc(r,c);
	if(r==1&&c==1)prl(0);
	else {
		if(r==1){
			rep(i,0,c){
				pr(i+2,"");
			}
			prl("");
		}
		else {
			rep(i, 0, r) {
				pr((2 + i), "");
				rep(j, 1, c) {
					pr((2 + i) * (r + j + 1), "");
				}
				prl("");
			}
		}
	}
    return 0;
}