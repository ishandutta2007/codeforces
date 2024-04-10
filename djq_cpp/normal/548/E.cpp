#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int M=5e5+1;
int a[200005],h[200005],c[M],m[M],n,q,x,d;
vector<int> v[M];
long long r;
int main(){
	m[1]=1;
	for(int i=1;i<M;i++)for(int j=i;j<M;j+=i){
		v[j].push_back(i);
		if(i<j)m[j]-=m[i];
	}
	cin>>n>>q;
	rep(k,n)cin>>a[k];
	rep(i,q){
		cin>>x;x--;
		rep(j,v[a[x]].size()){
			d=v[a[x]][j];
			c[d]-=h[x];
			r+=(h[x]?-1:1)*m[d]*c[d];
			c[d]+=!h[x];
		}
		h[x]^=1;
		cout<<r<<'\n';
	}
	return 0;
}