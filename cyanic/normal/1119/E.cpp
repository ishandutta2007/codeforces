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

const int N=300005;
ll f[N],s[N],a[N];
int n;

int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	ll free,now,mx;
	rep(i,1,n){
		free=s[i-1]-3*f[i-1],now=a[i];
		rep(t,0,2){
			mx=max(0ll,min((free-t)/3,(now-2*t)/6));
			if(mx*3+t<=free&&mx*6+2*t<=now)
				f[i]=max(f[i],3*mx+t+(now-6*mx-2*t)/3);
		}
		f[i]+=f[i-1];
	}
	cout<<f[n]<<endl;
	return 0;
}