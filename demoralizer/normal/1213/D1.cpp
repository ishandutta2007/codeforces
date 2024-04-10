#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int arr[200005];
int ei[500005];
int si[500005];

int ans=M;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	rep(i,1,500001){
		ei[i]=lower_bound(arr,arr+n,i+1)-arr;
		si[i]=lower_bound(arr,arr+n,i)-arr;
		//cout<<i<<" "<<si[i]<<" "<<ei[i]<<"\n";
	}
	rep(i,1,arr[n-1]+1){
		int vl=i,vu=i;
		int l=si[i];
		int u=ei[i];
		int t=u-l,m=0;
		if(t>=k){
			ans=0;
			break;
		}
		vl*=2;
		vu=2*vu+1;
		int c=1;
		while(vl<200001){
if(vu>200000)vu=200000;
			u=ei[vu];
			l=si[vl];
			if(t+u-l<k){
				t+=u-l;
				m+=(u-l)*c;
			}
			else{
				m+=c*(k-t);
				t=k;
				break;
			}
			vl*=2;
			vu=2*vu+1;
			c++;
		}
		if(t==k){
			ans=min(ans,m);
			// cout<<i<<" "<<m<<"\n";
		}
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}