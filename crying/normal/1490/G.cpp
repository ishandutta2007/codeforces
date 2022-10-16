#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const ll MAXN=2e5+10,INF=1e18;
int T,n,m;
ll a[MAXN],sum[MAXN],maxval,x,minv[MAXN];
struct Node{
	ll pos,v;
	bool operator<(const Node& n2)const{
		if(v!=n2.v)return v<n2.v;
		else return pos<n2.pos;
	}
}node[MAXN];
ll bs(ll lim){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(node[mid].v>=lim){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return minv[ans]-1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		sum[0]=0;
		maxval=-INF;
		rep(i,1,n){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
			maxval=max(maxval,sum[i]);
			node[i].v=sum[i];
			node[i].pos=i;	
		}
		sort(node+1,node+1+n);
		minv[n+1]=INF;
		per(i,n,1){
			minv[i]=min(minv[i+1],node[i].pos);
		}
		rep(i,1,m){
			cin>>x;
			if(sum[n]<=0){
				if(maxval<x)cout<<-1<<' ';
				else cout<<bs(x)<<' ';
				continue;
			}
			if(x<=maxval){
				cout<<bs(x)<<' ';
				continue;
			}
			ll cnt=(x-maxval)/sum[n];
			if((x-maxval)%sum[n])cnt++;
			cnt=max(cnt,0LL);
			x-=cnt*sum[n];
			printf("%lld ",1LL*n*cnt+bs(x)); 
		}
		cout<<endl;
	}
}