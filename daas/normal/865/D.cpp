#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
#define ll long long
using namespace std;
const int mod=1e9+7;
inline int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
priority_queue<int> Q;
int n;
ll ans;
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		int P=read();
		Q.push(-P),Q.push(-P);
		ans+=P+Q.top();
		Q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}