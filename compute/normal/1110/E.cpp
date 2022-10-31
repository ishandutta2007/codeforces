#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long arr[maxn];
long long brr[maxn];
long long a[maxn],b[maxn];
map<long long,int> cnta;
map<long long,int> cntb;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	for(int i=0;i<n;i++)
		scanf("%lld",&brr[i]);
	if(arr[0]!=brr[0])
		puts("No");
	else{
		for(int i=1;i<n;i++)
		{
			long long cur=arr[i]-arr[i-1];
			cnta[cur]++;
			cur=brr[i]-brr[i-1];
			cntb[cur]++;
		}
		bool ok=1;
		for(auto &p:cnta)
		{
			if(p.second!=cntb[p.first])
				ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
}