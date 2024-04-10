#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e4+10;
struct State{
	string s;
	int cost;
	bool operator<(const State& S2){if(cost!=S2.cost)return cost<S2.cost;return s<S2.s;}
}ans;
int n,k,t[20];
string s;
void solve(int a){
	//ka 
	State ret=(State){s,0};
	if(t[a]>=k){ans=Min(ans,ret);return;}
	int rest=k-t[a];
	rep(d,1,9){
		//d
		//a+d
		if(a+d<=9){
			if(rest>t[a+d]){
				ret.cost+=t[a+d]*d;
				rep(j,0,n-1){
					if(ret.s[j]-'0'==a+d){ret.s[j]='0'+a;}
				}
				rest-=t[a+d];
			}else{
				// 
				ret.cost+=rest*d;
				rep(j,0,n-1){
					if(!rest)break;
					if(ret.s[j]-'0'==a+d){rest--;ret.s[j]='0'+a;}
				}
				ans=Min(ans,ret); 
				return;
			}
		}
		//a-d 
		if(a-d>=0){
			if(rest>t[a-d]){
				ret.cost+=t[a-d]*d;
				rep(j,0,n-1){
					if(ret.s[j]-'0'==a-d){ret.s[j]='0'+a;}
				}
				rest-=t[a-d];
			}else{
				// 
				ret.cost+=rest*d;
				per(j,n-1,0){
					if(!rest)break;
					if(ret.s[j]-'0'==a-d){rest--;ret.s[j]='0'+a;}
				}
				ans=Min(ans,ret); 
				return;
			}
		}
	}
}
int main(){
	cin>>n>>k>>s;ans.cost=1e9;
	rep(i,0,n-1){t[s[i]-'0']++;}
	rep(j,0,9){
		solve(j);
	} 
	cout<<ans.cost<<'\n'<<ans.s;
	return 0;
}