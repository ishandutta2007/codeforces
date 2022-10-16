#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,k,a[10005],book[10005],num,ans;
signed main(){
	cin>>n>>k;
	num=(n+1)/2;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		book[a[i]]++;
	}
	for (int i=1;i<=k;i++){
		ans+=book[i]/2*2;
		num-=book[i]/2;
		book[i]%=2;
	}
	for (int i=1;i<=k;i++){
		if (num>0&&book[i]==1)book[i]=0,num--,ans++;
	}
	cout<<ans<<endl;
	return 0;
}