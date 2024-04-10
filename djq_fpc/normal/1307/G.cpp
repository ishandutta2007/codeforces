#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,cnt,dis[55],pre[55],prb[55],flw,res[55],inq[55];
struct edg
{
	int y,z,d;
}e[100005];
vector<int> bi[55];
void add(int x,int y,int z,int d)
{
	cnt++;
	bi[x].push_back(cnt*2-2);
	bi[y].push_back(cnt*2-1);
	e[cnt*2-2]=(edg){y,z,d};
	e[cnt*2-1]=(edg){x,0,-d};
}
bool bfs(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<int> qx;
	qx.push(s);
	while(!qx.empty()){
		int x=qx.front();qx.pop();inq[x]=0;
		ff(bi[x],it){
			if(e[*it].z){
				if(dis[e[*it].y]>dis[x]+e[*it].d){
					dis[e[*it].y]=dis[x]+e[*it].d;
					pre[e[*it].y]=x;
					prb[e[*it].y]=*it;
					if(!inq[e[*it].y]){
						inq[e[*it].y]=1;
						qx.push(e[*it].y);
					}
				}
			}
		}
	}
	return dis[n]<dis[n+1];
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,1,z);
	}
	while(bfs(1,n)){
		res[++flw]=dis[n];
		int t=n;
		while(t!=1){
			e[prb[t]].z--;
			e[prb[t]^1].z++;
			t=pre[t];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		double x;
		scanf("%lf",&x);
		fz1(i,flw-1){
			if((res[i+1]-res[i])*i>x) break;
			x-=(res[i+1]-res[i])*i;
		}
		printf("%.10f\n",res[i]+x/i);
	}
	return 0;
}