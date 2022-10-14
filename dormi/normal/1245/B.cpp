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
		int n,a,b,c;
		sc(n,a,b,c);
		char in;
		int win=0;
		char arr[n];

		rep(i,0,n){
			arr[i]='@';
			sc(in);
			if(in=='R'){
				if(b>0){
					b-=1;
					win+=1;
					arr[i]='P';
				}
			}
			if(in=='P'){
				if(c>0){
					c-=1;
					win+=1;
					arr[i]='S';
				}
			}
			if(in=='S'){
				if(a>0){
					a-=1;
					win+=1;
					arr[i]='R';
				}
			}
		}
		rep(i,0,n){
			if(arr[i]=='@'){
				if(a>0){
					a-=1;
					arr[i]='R';
				}
				else if(b>0){
					b-=1;
					arr[i]='P';
				}
				else{
					c-=1;
					arr[i]='S';
				}
			}
		}
		if(win>=n/2+((n%2)?1:0)){
			prl("YES");
			for(char x:arr)pr(x);
			prl("");
		}
		else prl("NO");
	}
    return 0;
}