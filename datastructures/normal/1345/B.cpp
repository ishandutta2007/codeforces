#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,ans;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		while(n>=2){
			int now=0;
			for (int i=1;i<=n;i++){
				if (i*(i+1)/2*3-i<=n)now=i;
				else break;
			}
			n-=now*(now+1)/2*3-now,ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}