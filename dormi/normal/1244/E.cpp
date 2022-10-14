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
    int n;
    lli k;
    sc(n,k);
    map<lli,int> nums;
    lli in;
    rep(i,0,n){
    	sc(in);
    	nums[in]+=1;
    }
    while(k&&sz(nums)>1){
        if(nums.begin()->second<=nums.rbegin()->second){
			lli nt=next(nums.begin(),1)->first;
			if((nt-nums.begin()->first)*nums.begin()->second<=k){
				k-=(nt-nums.begin()->first)*nums.begin()->second;
				nums[nt]+=nums.begin()->second;
				nums.erase(nums.begin()->first);
			}
			else{
				prl(nums.rbegin()->first-nums.begin()->first-k/nums.begin()->second);
				return 0;
			}
        }
        else{
	        lli nt=next(nums.rbegin(),1)->first;
	        if((nums.rbegin()->first-nt)*nums.rbegin()->second<=k){
		        k-=(nums.rbegin()->first-nt)*nums.rbegin()->second;
		        nums[nt]+=nums.rbegin()->second;
		        nums.erase(nums.rbegin()->first);
	        }
	        else{
		        prl(nums.rbegin()->first-nums.begin()->first-k/nums.rbegin()->second);
		        return 0;
	        }
        }
    }
    prl(nums.rbegin()->first-nums.begin()->first);
    return 0;
}