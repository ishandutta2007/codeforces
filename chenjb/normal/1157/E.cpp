#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int a[210000];
multiset<int> dic;
int main()
{
	int n;
	cin>>n;
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){ int x; scanf("%d",&x); dic.insert(x); }
	rep(i,n)
	{
		if (i!=1)putchar(' ');
		auto it1=dic.begin();
		auto it2=dic.lower_bound(n-a[i]);
		if (it2!=dic.end() && (a[i]+*it1)%n>(a[i]+*it2)%n)it1=it2;
		printf("%d",(*it1+a[i])%n); dic.erase(it1);
	}
	puts("");
}