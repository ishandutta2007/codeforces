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
	int t;
	sc(t);
	while(t--) {
		int n;
		sc(n);
		int arr[n+1];
		arr[0]=0;
		rep(i, 1, n+1) {
			sc(arr[i]);
		}
		int cnt = 0;
		int in;
		bool work=true;
		int last=0;
		rep(i, 1, n+1) {
			sc(in);
			if (in-arr[i]<0) {
				work=false;
			}
			if(in-arr[i]!=0&&in-arr[i]!=last)cnt++;
			last=in-arr[i];
		}
		if(!work||cnt>1){
			prl("NO");
		}
		else prl("YES");
	}
    return 0;
}