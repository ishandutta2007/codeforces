#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[200005],b[200005];
int cnt[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)scanf("%d",&b[i]);
		for (int i=1;i<=n;i++)cnt[i]=0;
		int p1=1,p2=1;
		while(p1<=n){
			if (p2<=n&&b[p1]==a[p2])p1++,p2++;
			else{
				if (p1>1&&b[p1]==b[p1-1]&&cnt[b[p1]]>0)cnt[b[p1]]--,p1++;
				else{
					if (p2>n)break;
					cnt[a[p2]]++,p2++;
				}
			}
		}
		if (p1<=n)puts("NO");
		else puts("YES");
	}
	return 0;
}