#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; int m,e[N][3];
void adde(int u,int v,int c){
	e[++m][0]=u,e[m][1]=v,e[m][2]=c;
}
int main(){
	int l,r,n=32; cin>>l>>r;
	if (l!=1) adde(n-1,n,l-1),r=r-l+1,--n;
	rep(i,1,20){//n-i -> n [1,2^(i-1)]
		rep(j,n-i+1,n-1) adde(n-i,j,1<<n-j-1);
		adde(n-i,n,1);
	}
	adde(1,n,1),--r;
	int v=0;
	rep(j,1,20) //[1,v+1] [v+2,v+1+2^j]
		if (r>>j-1&1) adde(1,n-j,v+1),v|=1<<j-1;
	cout<<"YES"<<endl<<32<<" "<<m<<endl;
	rep(i,1,m) cout<<e[i][0]<<" "<<e[i][1]<<" "<<e[i][2]<<endl;
}