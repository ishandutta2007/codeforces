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
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110;
ll t,n,l,r,now;
vector<int>q;
int main(){
	cin>>t;
	while(t--){
		while(q.size())q.pop_back();
		cin>>n>>l>>r;
		now=1;
		rep(i,1,n-1){
			if(now>r)break;
			if(now+2*(n-i)-1<l){
				now=now+2*(n-i);continue;
			}
			if(now>=l && now+2*(n-i)-1<=r){
				//
				rep(j,i+1,n)q.pb(i),q.pb(j); 
			}else if(now>=l){
				// 
				ll cnt=now;
				rep(j,i+1,n){
					q.pb(i);cnt++;
					if(cnt>r)break;
					q.pb(j);cnt++;
					if(cnt>r)break;
				} 
			}else if(now+2*(n-i)-1<=r){
				//
				ll cnt=now+2*(n-i)-1;
				per(j,n,i+1){
					q.pb(j);cnt--;
					if(cnt<l)break;
					q.pb(i);cnt--;
					if(cnt<l)break;
				}
				reverse(q.begin(),q.end());
			}else{
				//
				ll cnt=now;
				rep(j,i+1,n){
					if(cnt>=l&&cnt<=r)q.pb(i);cnt++;
					if(cnt>=l&&cnt<=r)q.pb(j);cnt++;
				}
				break; 
			}
			now=now+2*(n-i);
		}
		if(r==n*(n-1)+1)q.pb(1);
		for(vit it=q.begin();it!=q.end();it++){
			printf("%d ",*it);
		}
		printf("\n");
	}
	return 0;
}