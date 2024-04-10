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
int a[N],b[N],n,m;

int main(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	rep(i,1,m)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]>b[1])return puts("-1"),0;
	ll sum=0,sum2=0,ans=0;
	rep(i,1,n-1)sum+=a[i];
	rep(i,1,m)sum2+=b[i];
	ans=sum*m+sum2+(a[n]<b[1]?a[n]-a[n-1]:0);
	cout<<ans<<endl;
	return 0;
}