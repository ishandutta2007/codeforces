#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=110;
int T,n,arr[MAXN];

void solve(){
	cin>>n;
	rep(i,1,n)arr[i]=i;
	reverse(arr+1,arr+n-1);
	if(odd(n))swap(arr[n-3],arr[n-4]);
	rep(i,1,n)cout<<arr[i]<<" ";cout<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
	
	return 0;
}