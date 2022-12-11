#include<bits/stdc++.h>
typedef long long LL;
int n,q;
struct Point
{
	int x,y;
	Point(int _x=0,int _y=0):
		x(_x),y(_y){}
	friend Point Normal(const Point&p)
	{
		int g=std::__gcd(p.x,p.y);
		return Point(p.x/g,p.y/g);
	}
	friend Point Mid(const Point&l,const Point&r)
	{
		return Normal(Point(l.x+r.x,l.y+r.y));
	}
	friend LL Calc(const Point&p)
	{
		return 1LL*p.x*p.x+1LL*p.y*p.y;
	}
	friend bool operator<(const Point&l,const Point&r)
	{
		return (l.x==r.x?l.y<r.y:l.x<r.x);
	}
	friend bool operator==(const Point&l,const Point&r)
	{
		return l.x==r.x&&l.y==r.y;
	}
};
std::map<LL,std::set<Point>>Circle;
std::map<Point,int>ans;
inline void Solve()
{
	scanf("%d",&q);
	for(int i=1,opt,x,y;i<=q;++i)
	{
		scanf("%d%d%d",&opt,&x,&y);
		switch(opt)
		{
			case 1:
			{
				Point p(x,y);
				++n;
				++ans[Normal(p)];
				auto&C=Circle[Calc(p)];
				for(auto v:C)
				ans[Mid(p,v)]+=2;
				C.insert(p);
				break;
			}
			case 2:
			{
				Point p(x,y);
				--n;
				--ans[Normal(p)];
				auto&C=Circle[Calc(p)];
				for(auto v:C)
				{
					if(v==p)continue;
					ans[Mid(p,v)]-=2;
				}
				C.erase(C.find(p));
				break;
			}
			case 3:
			{
				Point p(x,y);
				printf("%d\n",n-ans[Normal(p)]);
				break;
			}
		}
	}
}
int main()
{
	Solve();
	return 0;
}