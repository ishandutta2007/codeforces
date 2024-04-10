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
int arr[10][10];
long double dp[10][10];
long double thingy=(long double)1/(long double)6;
long double go(int x, int y){
	if(dp[x][y]!=-1)return dp[x][y];
	long double moves=0;
	if(x==0&&y<=5){
		rep(i,1,y+1){
			int ne=i;
			if(x%2==0)ne*=-1;
			int ynew=y+ne;
			int xnew=x;
			if(ynew<0){
				ynew=abs(ynew)-1;
				xnew-=1;
			}
			else if(ynew>=10){
				ynew=9-(ynew-10);
				xnew-=1;
			}
			long double todo=min(go(xnew,ynew),go(xnew-arr[xnew][ynew],ynew));
			moves+=thingy*(1+todo);
		}
		long double b=(long double)(6-y)/(long double)6;
		moves=(moves+b)/(1-b);
	}
	else {
		rep(i, 1, 7) {
			int ne = i;
			if (x % 2 == 0)ne *= -1;
			int ynew = y + ne;
			int xnew = x;
			if (ynew < 0) {
				ynew = abs(ynew) - 1;
				xnew -= 1;
			} else if (ynew >= 10) {
				ynew = 9 - (ynew - 10);
				xnew -= 1;
			}
			long double todo = min(go(xnew, ynew),  go(xnew - arr[xnew][ynew], ynew) );
			moves += thingy * (1+todo);
		}
	}
	return dp[x][y]=moves;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    rep(i,0,10){
    	rep(j,0,10){
    		dp[i][j]=-1;
    		sc(arr[i][j]);
    	}
    }
    dp[0][0]=0;
	cout<<fixed<<setprecision(10)<<go(9,0)<<"\n";
    return 0;
}