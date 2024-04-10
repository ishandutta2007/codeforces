#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
priority_queue<int> pq;
int main()
{
	int n=read(),x;long long ans=0;
	while(n--)
	{
		pq.push(x=-read());pq.push(x);
		ans+=pq.top()-x;pq.pop();
	}
	printf("%I64d",ans);
}