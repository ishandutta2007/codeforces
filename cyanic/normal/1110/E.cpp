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
int c[N],t[N],a[N],b[N],n;

int main(){
	cin>>n;
	rep(i,1,n)cin>>c[i];
	rep(i,1,n)cin>>t[i];
	rep(i,1,n-1)a[i]=c[i+1]-c[i];
	rep(i,1,n-1)b[i]=t[i+1]-t[i];
	sort(a+1,a+n);
	sort(b+1,b+n);
	rep(i,1,n-1)
		if(a[i]!=b[i]){
			puts("No");
			return 0;
		}
	if(c[1]!=t[1]||c[n]!=t[n])puts("No");
	else puts("Yes");

	return 0;
}