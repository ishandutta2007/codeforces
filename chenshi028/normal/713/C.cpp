#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e5+10;
int n;long long a[o],b;priority_queue<long long> q;
int main(){
	read(n);b=0;
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) a[i]-=(i-1);
	q.push(a[1]);q.push(a[1]);b=-a[1];
	for(int i=2;i<=n;++i) b+=q.top(),q.pop(),q.push(a[i]),q.push(a[i]),b+=-a[i];
	printf("%lld\n",q.top()+b);
	return 0;
}