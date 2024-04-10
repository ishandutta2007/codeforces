#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#define int long long
using namespace std;
int n,a[200005],cnt[25],ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for (int j=0;j<=20;j++)
			if (a[i]&(1<<j))cnt[j]++;
	}
	for (int i=1;i<=n;i++){
		int num=0;
		for (int j=0;j<=20;j++)
			if (cnt[j]>0)num+=(1<<j),cnt[j]--;
		ans+=num*num;
	}
	cout<<ans<<endl;
	return 0;
}