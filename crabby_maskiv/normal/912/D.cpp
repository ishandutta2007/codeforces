#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1000000007ll;
ll n,m;
priority_queue<pair<ll,pair<int,int> > > q;
ll r,k;
ll f(ll x,ll y){
	return (min(x+r-1,n)-max(x,r)+1)*(min(y+r-1,m)-max(y,r)+1);
}
set<pair<ll,ll> > st;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main() {
	int i,j;
	cin>>n>>m>>r>>k;
	q.push({f((n+1)/2,(m+1)/2),{(n+1)/2,(m+1)/2}});
	st.insert({(n+1)/2,(m+1)/2});
	ll sum=0;
	while(k--){
		pair<ll,pair<int,int> > p=q.top();q.pop();
		ll s=p.first,x=p.second.first,y=p.second.second;
		//cout<<s<<endl;
		sum+=s;
		for(i=0;i<4;i++){
			ll tx=x+dx[i],ty=y+dy[i];
			if(st.find({tx,ty})!=st.end()) continue;
			st.insert({tx,ty});
			q.push({f(tx,ty),{tx,ty}});
		}
	}
	double ans=double(sum)/double((n-r+1)*(m-r+1));
	printf("%.9f",ans);
    return 0;
}