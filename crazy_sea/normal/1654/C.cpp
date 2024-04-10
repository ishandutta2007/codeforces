#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
#define ll long long
using namespace std;
const int N=2e5+10;
int T,n,a[N];
unordered_map<ll,int>t;
priority_queue<ll>q;
ll s,x,y,z;
bool chk()
{
	if(n==1) return 1;
	while(!q.empty()) q.pop();
	int sum=0;
	q.push(s);
	for(int i=1;i<n;i++)
	{
		if(q.empty()) return 0;
		x=q.top();q.pop();
		if(x&1) y=x/2,z=y+1;
		else y=z=x/2;
		if(!t[y]) q.push(y);
		else t[y]--,sum++;
		if(!t[z]) q.push(z);
		else t[z]--,sum++;
	}
	return sum==n;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i],t[a[i]]++;
		printf("%s\n",chk()?"YES":"NO");
		s=0;
		t.clear();
	}
}