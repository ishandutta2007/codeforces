#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=5e5+100;

struct Pt{int x,y,id;}P[MX];
bool operator<(const Pt& a,const Pt& b)
{
	return a.x<b.x||(a.x==b.x&&a.y>b.y);
}
int ans[MX];


int mian()
{
	int n;
	scanf("%d",&n);
	int N=2*n;
	Fr(i,1,n)scanf("%d%d",&P[i].x,&P[i].y),P[i].id=i;
	Fr(i,n+1,N)P[i].x=P[i-n].y,P[i].y=P[i-n].x,P[i].id=i-n;
	
	sort(P+1,P+1+N);
	stack<Pt> stk;
	Fr(i,1,n)ans[i]=-1;
	Fr(i,1,N)
	{
		Pt pt=P[i];
		while(!(stk.empty()||stk.top().y<pt.y))stk.pop();
		if(!stk.empty()&&ans[pt.id]==-1)ans[pt.id]=stk.top().id;
		stk.push(pt);
	}
	Fr(i,1,n)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}