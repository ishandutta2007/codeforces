#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x1,x2,y1,y2;
}a,b,c;
int main()
{
	cin>>a.x1>>a.y1>>a.x2>>a.y2>>b.x1>>b.y1>>b.x2>>b.y2>>c.x1>>c.y1>>c.x2>>c.y2;
	if(c.x1<=a.x1&&c.x2>=a.x2 &&c.y1<=a.y1&&c.y2>=a.y2 ) puts("NO");
	else if(b.x1<=a.x1&&b.x2>=a.x2 &&b.y1<=a.y1&&b.y2>=a.y2 ) puts("NO");
	else if(c.x1<=a.x1&&c.x2>=a.x2&&b.x1<=a.x1&&b.x2>=a.x2&&b.y1<=a.y1&&c.y2>=a.y2&&b.y2>=c.y1) puts("NO");
	else if(c.x1<=a.x1&&c.x2>=a.x2&&b.x1<=a.x1&&b.x2>=a.x2&&c.y1<=a.y1&&b.y2>=a.y2&&c.y2>=b.y1) puts("NO");
    else if(c.y1<=a.y1&&c.y2>=a.y2&&b.y1<=a.y1&&b.y2>=a.y2&&b.x1<=a.x1&&c.x2>=a.x2&&b.x2>=c.x1) puts("NO");
    else if(c.y1<=a.y1&&c.y2>=a.y2&&b.y1<=a.y1&&b.y2>=a.y2&&c.x1<=a.x1&&b.x2>=a.x2&&c.x2>=b.x1) puts("NO");
    else puts("YES");
}