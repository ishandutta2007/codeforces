#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int a,b,c;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int sum=0;
		scanf("%d%d%d",&a,&b,&c);
		if(a) sum++,a--;
		if(b) sum++,b--;
		if(c) sum++,c--;
		if(a<b) swap(a,b);
		if(b<c) swap(b,c);
		if(a<b) swap(a,b);
		if(c&&a) sum++,a--,c--;
		if(b&&a) sum++,b--,a--;
		if(b&&c) sum++,b--,c--;
		if(a&&b&&c) sum++;
		printf("%d\n",sum);
	}
	return 0;
}