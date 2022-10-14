#include<bits/stdc++.h>
using namespace std;
int a[1003];
int _main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	bool f=0; int k;
	for(int i=1; i<=n; i++) if(a[i]%2) if(f) return printf("2\n%d %d\n",k,i); else f=1,k=i; else return printf("1\n%d\n",i);
	return printf("-1\n");
	//qwq
}
int main()
{
	int t;
	cin>>t;
	while(t--) _main();
}