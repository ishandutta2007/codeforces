#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int N=100005;
priority_queue<int,vector<int>,greater<int> > Q;
int a[N],b[N],n,K,now;
ll ans;
int main(){
	cin >> n >> now;
	rep(i,1,n) cin >> a[i];
	cin >> K;
	rep(i,1,n) cin >> b[i];
	rep(i,1,n){
		Q.push(b[i]);
		while(now<a[i]){
			if(Q.empty()){
				puts("-1");
				return 0;
			}
			now+=K;
			ans+=Q.top();
			Q.pop();
		}
		if(now<a[i]){
			puts("-1");
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}