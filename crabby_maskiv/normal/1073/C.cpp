#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
ll tx,ty,x,y;
int cntu[N],cntd[N],cntr[N],cntl[N];
ll f(ll p){
	return p<0?-p:p;
}
bool check(int key){
	int i;
	for(i=1;i+key-1<=n;i++){
		int l=cntl[i+key-1]-cntl[i-1];
		int r=cntr[i+key-1]-cntr[i-1];
		int u=cntu[i+key-1]-cntu[i-1];
		int d=cntd[i+key-1]-cntd[i-1];
		int cx=x-r+l,cy=y-u+d;
		ll dis=f(cx-tx)+f(cy-ty);
		if(dis<=key&&!((dis-key)&1))return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>(a+1);
	for(i=1;i<=n;i++){
		if(a[i]=='U'){
			y++;cntu[i]++;
		}
		if(a[i]=='D'){
			y--;cntd[i]++;
		}
		if(a[i]=='L'){
			x--;cntl[i]++;
		}
		if(a[i]=='R'){
			x++;cntr[i]++;
		}
	}
	cin>>tx>>ty;
	for(i=1;i<=n;i++){
		cntl[i]+=cntl[i-1];
		cntr[i]+=cntr[i-1];
		cntu[i]+=cntu[i-1];
		cntd[i]+=cntd[i-1];
	}
	if(x==tx&&y==ty){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(r-l>5){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	for(i=l;i<=r;i++){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}