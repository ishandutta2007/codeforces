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
	int t;
	sc(t);
	while(t--){
		int n;
		sc(n);
		map<int,int> used;
		int cur;
		int am=0;
		string arr[n];
		int th[n];
		rep(i,0,n){
			sc(th[i]);
			used[th[i]]+=1;
		}
		rep(i,0,n){
			cur=th[i];
			int d=0;
			used[cur]-=1;
			while(used.count(cur)&&used[cur]){
				cur=(cur+1000)%10000;
				d=1;
			}
			used[cur]+=1;
			arr[i]=to_string(cur);
			am+=d;
		}
		prl(am);
		rep(i,0,n){
			while(sz(arr[i])<4)arr[i]="0"+arr[i];
			prl(arr[i]);
		}
	}
    return 0;
}