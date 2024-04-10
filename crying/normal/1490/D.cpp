#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MAXN=110;
int T,n,depth[MAXN],a[MAXN];
void build(int l,int r,int level){
	if(l>r)return;
	if(l==r){
		depth[l]=level;return;
	}
	int rt=0;
	rep(i,l,r){
		if(a[i]>a[rt])rt=i;
	}
	depth[rt]=level;
	build(l,rt-1,level+1);
	build(rt+1,r,level+1);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		memset(depth,0,sizeof depth);
		build(1,n,0);
		rep(i,1,n){
			cout<<depth[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}