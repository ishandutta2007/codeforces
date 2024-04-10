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
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const int N=100005;
int h[N],a[N],need[N];
int n,m,k,p;
 
bool check(ll aim){
	int rem=k*m;
	rep(i,1,m)need[i]=0;
	rep(i,1,n){
		ll now=aim,cnt=0;
		int day=m+1;
		while(day>=2){
			int t=min((ll)day-1,now/a[i]);
			now-=(ll)t*a[i],day-=t;
			if(day>=2&&now<a[i]){
				ll t=(a[i]-now+p-1)/p;
				if((rem-=t)<0)return 0;
				now+=p*t,need[day]+=t,cnt+=t;
			}
		}
		if(now<h[i]){
			ll t=(h[i]-now+p-1)/p;
			if((rem-=t)<0)return 0;
			now+=p*t,need[day]+=t,cnt+=t;
		}
	}
	int total=0;
	rep(i,1,m){
		total+=need[i];
		total=max(0,total-k);
	}
	return !total;
}
 
int main(){
	read(n),read(m);
	read(k),read(p);
	ll l=0,r=1e15,mid;
	rep(i,1,n){
		read(h[i]),read(a[i]);
		l=max(l,(ll)a[i]);
	}
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}