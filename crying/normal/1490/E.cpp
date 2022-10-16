#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MAXN=2e5+10;
int T,n,vis[MAXN],cnt;
struct Node{
	int u,idx;
	bool operator<(const Node& n2)const{
		return u<n2.u;
	}
}node[MAXN];
ll sum[MAXN],f[MAXN]; //f(i)1~in 
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		rep(i,1,n){
			vis[i]=0;
			sum[i]=0;
			f[i]=0;
			cin>>node[i].u;
			node[i].idx=i;
		}
		sum[n+1]=0;
		f[0]=f[n+1]=0;
		sort(node+1,node+1+n);
		// 
		rep(i,1,n){
			sum[i]=sum[i-1]+node[i].u;
		} 
		//dp
		f[n]=1;
		per(i,n-1,1){
			f[i]=f[i+1] && (sum[i]>=node[i+1].u);
		}
		rep(i,1,n){
			if(f[i])vis[node[i].idx]=1;
		}
		per(i,n-1,1){
			if(node[i].u==node[i+1].u)vis[node[i].idx]=vis[node[i+1].idx];
		}
		rep(i,1,n)if(vis[i])cnt++;
		cout<<cnt<<endl;
		rep(i,1,n){
			if(vis[i])cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}