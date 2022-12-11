#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int x,y;}p[8];
bool cmp(node a,node b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int mx[1000005],my[1000005];
const int o[8][2]={{1,1},{1,2},{1,3},{2,1},{2,3},{3,1},{3,2},{3,3}};
int main()
{
	int i,cnt=0;
	for(i=0;i<8;++i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p,p+8,cmp);
	mx[p[0].x]=1;mx[p[3].x]=2;mx[p[5].x]=3;
	my[p[0].y]=1;my[p[1].y]=2;my[p[2].y]=3;
	for(i=0;i<8;++i)if(mx[p[i].x]!=o[i][0]||my[p[i].y]!=o[i][1])return 0*puts("ugly");
	puts("respectable");
}