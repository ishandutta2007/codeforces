#include<cstdio>
#include<algorithm>
#include<vector>
#define MaxN 2650
typedef long long LL;
inline LL Binom(int n,int m)
{
	LL res=1;
	for(int i=0;i<m;++i)res=res*(n-i)/(i+1);
	return res;
}
int n;
LL ans1,ans2;
struct Point
{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){}
};
typedef Point Vector;
inline Vector operator-(Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
inline LL Cross(Vector a,Vector b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
inline int Quadrant(Vector a)
{
	if(a.x>0&&a.y>=0)return 1;
	if(a.x<=0&&a.y>0)return 2;
	if(a.x<0&&a.y<=0)return 3;
	if(a.x>=0&&a.y<0)return 4;
}
Point p[MaxN];
int main()
{
	scanf("%d",&n);
	ans1=Binom(n,5);
	for(int i=1;i<=n;++i)
	scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=n;++i)
	{
		std::vector<Vector>v;
		for(int j=1;j<=n;++j)
		if(i!=j)v.push_back(p[j]-p[i]);
		auto cmp=[](Vector a,Vector b)
		{return Quadrant(a)==Quadrant(b)?Cross(a,b)>0:Quadrant(a)<Quadrant(b);};
		std::sort(v.begin(),v.end(),cmp);
		for(int j=0,m=0;j<v.size();++j)
		{
			while(m<j+v.size()&&Cross(v[j],v[m%v.size()])>=0)++m;
			ans2+=Binom(m-j-1,3);
		}
	}
	printf("%lld\n",5*ans1-ans2);
	return 0;
}