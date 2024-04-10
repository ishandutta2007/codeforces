#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 5000
using namespace std;
int n;priority_queue<int> q;
int main()
{
	RI i,x;long long t=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&x),
		q.push(x),x<q.top()&&(t+=q.top()-x,q.pop(),q.push(x),0);return printf("%lld\n",t),0;
}