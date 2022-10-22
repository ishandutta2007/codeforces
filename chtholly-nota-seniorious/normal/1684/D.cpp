//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	for (i=0;i<n;i++) cout<<a[i]<<" \n"[i+1==n];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		vector<int> a(n),b(n);
		for (i=0;i<n;i++) cin>>a[i],b[i]=a[i]-(n-i-1);
		sort(all(b));reverse(all(b));
		cout<<accumulate(all(a),-accumulate(b.begin(),b.begin()+m,0ll))-m*(m-1ll)/2<<'\n';
	}
}