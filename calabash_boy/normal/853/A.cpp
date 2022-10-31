#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxn=300010;
struct node
{
	int c,id;
	node(int c=0,int id=0):c(c),id(id) {}
	bool operator < (const node& a) const 
	{
		return c<a.c;
	}
};
int t[maxn],n,k;
node data[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	set<int> nul;
	for(int i=0;i<n;i++) {scanf("%d",&data[i].c); data[i].id=i+1; nul.insert(i+k+1);}
	sort(data,data+n);
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	{
		node x=data[i];
		set<int>::iterator it=nul.begin();
		int b=*it;
		int key=max(b,x.id);
		t[x.id]=key;
		ans+=1LL*(key-x.id)*x.c;
		nul.erase(key);
	}
	printf("%I64d\n",ans);
	for(int i=1;i<n;i++) printf("%d ",t[i]);
	printf("%d\n",t[n]);
	return 0;
}