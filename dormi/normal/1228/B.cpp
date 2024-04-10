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
lli mod=1e9+7;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(i&b){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int h,w;
    sc(h,w);
    int grid[h+1][w+1];
    memset(grid,0,sizeof(grid));
    int in;
    rep(i,0,h){
    	sc(in);
    	rep(j,0,in){
    		if(grid[i][j]==2){
    			prl(0);
    			return 0;
    		}
    		grid[i][j]=1;
    	}
    	if(grid[i][in]==1){
		    prl(0);
		    return 0;
    	}
	    grid[i][in]=2;
    }
	rep(i,0,w){
		sc(in);
		rep(j,0,in){
			if(grid[j][i]==2){
				prl(0);
				return 0;
			}
			grid[j][i]=true;
		}
		if(grid[in][i]==1){
			prl(0);
			return 0;
		}
		grid[in][i]=2;
	}
	lli cnt=0;
	rep(i,0,h){
    	rep(j,0,w){
    		if(grid[i][j]==0){
    			cnt++;
    		}
    	}
    }
    prl(fastpow(2,cnt));
    return 0;
}