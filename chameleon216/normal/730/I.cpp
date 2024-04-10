#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=3100,Inf=0x3f3f3f3f;
int N,P,S,A[MX],B[MX],id[MX];
struct Node
{
	int i,x;
	Node(){}
	Node(int i_,int x_){i=i_,x=x_;}
};
inline bool operator<(const Node& a,const Node& b){return a.x<b.x;}
priority_queue<Node> Q1,Q2,Q3,Q4; // 0->a,0->b,a->b,b->a

int main()
{
	scanf("%d%d%d",&N,&P,&S);
	Fr(i,1,N)scanf("%d",&A[i]),Q1.push(Node(i,A[i]));
	Fr(i,1,N)scanf("%d",&B[i]),Q2.push(Node(i,B[i]));
	int ans=0;
	while(1)
	{
		while(Q1.size()&&id[Q1.top().i]!=0)Q1.pop();
		while(Q2.size()&&id[Q2.top().i]!=0)Q2.pop();
		while(Q3.size()&&id[Q3.top().i]!=1)Q3.pop();
		while(Q4.size()&&id[Q4.top().i]!=2)Q4.pop();
		
		int o=0,x=0;
		if(P&&Q1.size()&&x<Q1.top().x)o=1,x=Q1.top().x;
		if(S&&Q2.size()&&x<Q2.top().x)o=2,x=Q2.top().x;
		if(P&&Q2.size()&&Q4.size()&&x<Q2.top().x+Q4.top().x)o=3,x=Q2.top().x+Q4.top().x;
		if(S&&Q1.size()&&Q3.size()&&x<Q1.top().x+Q3.top().x)o=4,x=Q1.top().x+Q3.top().x;
		
		if(o==1)
		{
			int i=Q1.top().i;
			ans+=x,id[i]=1,--P;
			Q3.push(Node(i,B[i]-A[i]));
		}
		else if(o==2)
		{
			int i=Q2.top().i;
			ans+=x,id[i]=2,--S;
			Q4.push(Node(i,A[i]-B[i]));
		}
		else if(o==3)
		{
			int i=Q2.top().i,j=Q4.top().i;
			ans+=x,id[i]=2,id[j]=1,--P;
			Q4.push(Node(i,A[i]-B[i]));
			Q3.push(Node(j,B[j]-A[j]));
		}
		else if(o==4)
		{
			int i=Q1.top().i,j=Q3.top().i;
			ans+=x,id[i]=1,id[j]=2,--S;
			Q3.push(Node(i,B[i]-A[i]));
			Q4.push(Node(j,A[j]-B[j]));
		}
		else break;
	}
	printf("%d\n",ans);
	Fr(i,1,N)if(id[i]==1)printf("%d ",i);
	putchar('\n');
	Fr(i,1,N)if(id[i]==2)printf("%d ",i);
	putchar('\n');
	return 0;
}