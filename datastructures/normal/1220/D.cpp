#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n,b[1000005],cnt[1000005],qwq,mx;
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++){
    	scanf("%lld",&b[i]);
    	int x=b[i];
    	while(x%2==0)cnt[i]++,x/=2;
	}
	for (int i=0;i<60;i++){
		int num=0;
		for (int j=1;j<=n;j++)
			if (cnt[j]==i)num++;
		if (num>mx)mx=num,qwq=i;
	}
	cout<<n-mx<<endl;
	for (int i=1;i<=n;i++)
		if (cnt[i]!=qwq)printf("%lld ",b[i]);
	puts("");
    return 0;
}