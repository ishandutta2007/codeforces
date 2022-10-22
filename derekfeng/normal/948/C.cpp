#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
using namespace std;
typedef long long ll;
ll n;
ll fn[100005];
ll t[100005],v[100005];
vector <ll> s[100005];
int main(){
	cin>>n;
	t[0]=0;
	for (ll i=1;i<=n;i++) cin>>v[i];
	for (ll i=1;i<=n;i++) cin>>t[i];
	for (ll i=1;i<=n;i++){
		v[i]+=t[i-1];
		t[i]+=t[i-1]; 
	}
	for (ll i=1;i<=n;i++){
		ll l=i,r=n;
		while (r>l){
			ll mid=(l+r)/2;
			if (t[mid]>=v[i]) r=mid;
			else l=mid+1;
		}
  		s[r].push_back(i); 
	}
	ll fn=0;
	for (ll i=1;i<=n;i++){ 
		ll ans=0;
		for (ll j=0;j<s[i].size();j++){
			ans+=1ll*min(v[s[i][j]],t[i])-t[i-1];
			fn++; 
		}
		ans+=(i-fn)*(t[i]-t[i-1]);
		cout<<ans<<" ";
	}
	return 0;
}