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

const int N=1000005;
int a[N],n,m,k,b,last,mn,mx,ans;

int main(){
	cin>>n>>m>>k;
	cin>>last,mn=last;
	rep(i,2,n){
		cin>>b;
		a[i-1]=b-last-1;
		last=b;
	}
	ans=last-mn+1;
	sort(a+1,a+n,greater<int>());
	rep(i,1,k-1)
		ans-=a[i];
	cout<<ans<<endl;

	return 0;
}