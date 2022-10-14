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
int xch[8]={2,2,-2,-2,1,1,-1,1};
int ych[8]={1,-1,1,-1,2,-2,2,-2};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    int arr[n][n];
    memset(arr,0,sizeof(arr));
    rep(i,0,n)rep(j,0,n){
    	if(arr[i][j]==0){
    		arr[i][j]=1;
    		queue<pii> q;
    		q.push({i,j});
    		while(!q.empty()){
    			pii cur=q.front();
    			q.pop();
			    rep(k,0,8){
					pii ne={cur.first+xch[k],cur.second+ych[k]};
					if(ne.first>=0&&ne.first<n&&ne.second>=0&&ne.second<n){
						if(arr[ne.first][ne.second]==0){
							arr[ne.first][ne.second]=((arr[cur.first][cur.second]%2)+1);
							q.push(ne);
						}
					}
			    }
    		}
    	}
    }
    rep(i,0,n)rep(j,0,n){
    	pr((arr[i][j]==1?'W':'B'));
    	if(j==n-1)prl("");
    }
    return 0;
}