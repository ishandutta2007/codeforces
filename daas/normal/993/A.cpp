#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const double eps=1e-8;
const double pi=acos(-1);
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
struct vec
{
	int x,y;
	vec(int _x=0,int _y=0) {x=_x,y=_y;}
	vec operator -(const vec &Z) const {return vec(x-Z.x,y-Z.y);}
}a[5],b[5];
int main()
{
	for(int i=0;i<4;++i) a[i].x=read(),a[i].y=read();
	a[4]=a[0];
	for(int i=0;i<4;++i) b[i].x=read(),b[i].y=read();
	b[4]=b[0];
	for(int x=-100;x<=100;++x)
		for(int y=-100;y<=100;++y)
		{
			if(min(min(a[0].x,a[1].x),a[2].x)<=x && x<=max(max(a[0].x,a[1].x),a[2].x) && min(min(a[0].y,a[1].y),a[2].y)<=y && y<=max(max(a[0].y,a[1].y),a[2].y))
			{
				if(min(min(b[0].x-b[0].y,b[1].x-b[1].y),b[2].x-b[2].y)<=x-y && x-y<=max(max(b[0].x-b[0].y,b[1].x-b[1].y),b[2].x-b[2].y) && min(min(b[0].x+b[0].y,b[1].x+b[1].y),b[2].x+b[2].y)<=x+y && x+y<=max(max(b[0].x+b[0].y,b[1].x+b[1].y),b[2].x+b[2].y))
				{
					puts("YES");
					return 0;
				}
			}
		}
	puts("NO");
	return 0;
}
//ore no turn,draw!