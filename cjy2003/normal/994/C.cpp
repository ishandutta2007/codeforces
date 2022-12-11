#include<stdio.h>
#include<string.h>
int xa[3],ya[3],xb[3],yb[3],maxx,maxy,minx,miny,x,y;
int main()
{
	for(int i=1;i<=4;i++)
	{
		scanf("%d %d",&x,&y);
		if(i==1)maxx=minx=x,maxy=miny=y;
		else
		{
			if(maxx<x)maxx=x;
			if(minx>x)minx=x;
			if(maxy<y)maxy=y;
			if(miny>y)miny=y;	
		}
	}
	xa[1]=minx,xa[2]=maxx,ya[1]=miny,ya[2]=maxy;
	for(int i=1;i<=4;i++)
	{
		scanf("%d %d",&x,&y);
		if(i==1)maxx=minx=x,maxy=miny=y;
		else
		{
			if(maxx<x)maxx=x;
			if(minx>x)minx=x;
			if(maxy<y)maxy=y;
			if(miny>y)miny=y;	
		}
	}
	xb[1]=minx,xb[2]=maxx,yb[1]=miny,yb[2]=maxy;
//	printf("%d %d %d %d %d %d %d %d\n",xa[1],xa[2],ya[1],ya[2],xb[1],xb[2],yb[1],yb[2]);
	x=xb[1],y=(yb[1]+yb[2])/2;
	if(x>=xa[1]&&x<=xa[2]&&y>=ya[1]&&y<=ya[2])
	{
		printf("YES");
		return 0;
	}
	x=(xb[1]+xb[2])/2,y=yb[2];
	if(x>=xa[1]&&x<=xa[2]&&y>=ya[1]&&y<=ya[2])
	{
		printf("YES");
		return 0;
	}
	x=xb[2],y=(yb[1]+yb[2])/2;
	if(x>=xa[1]&&x<=xa[2]&&y>=ya[1]&&y<=ya[2])
	{
		printf("YES");
		return 0;
	}
	x=(xb[1]+xb[2])/2,y=yb[1];
	if(x>=xa[1]&&x<=xa[2]&&y>=ya[1]&&y<=ya[2])
	{
		printf("YES");
		return 0;
	}
	x=(xb[1]+xb[2])/2,y=(yb[1]+yb[2])/2;
	if(x>=xa[1]&&x<=xa[2]&&y>=ya[1]&&y<=ya[2])
	{
		printf("YES");
		return 0;
	}
	x=xa[1],y=ya[1];
	if(x+y>=xb[1]+(yb[1]+yb[2])/2&&x+y<=xb[2]+(yb[1]+yb[2])/2&&y-x>=(yb[1]+yb[2])/2-xb[2]&&y-x<=(yb[1]+yb[2])/2-xb[1])
	{
		printf("YES");
		return 0;	
	}
	x=xa[1],y=ya[2];
	if(x+y>=xb[1]+(yb[1]+yb[2])/2&&x+y<=xb[2]+(yb[1]+yb[2])/2&&y-x>=(yb[1]+yb[2])/2-xb[2]&&y-x<=(yb[1]+yb[2])/2-xb[1])
	{
		printf("YES");
		return 0;	
	}
	x=xa[2],y=ya[1];
	if(x+y>=xb[1]+(yb[1]+yb[2])/2&&x+y<=xb[2]+(yb[1]+yb[2])/2&&y-x>=(yb[1]+yb[2])/2-xb[2]&&y-x<=(yb[1]+yb[2])/2-xb[1])
	{
		printf("YES");
		return 0;	
	}
	x=xa[2],y=ya[2];
	if(x+y>=xb[1]+(yb[1]+yb[2])/2&&x+y<=xb[2]+(yb[1]+yb[2])/2&&y-x>=(yb[1]+yb[2])/2-xb[2]&&y-x<=(yb[1]+yb[2])/2-xb[1])
	{
		printf("YES");
		return 0;	
	}
	x=(xa[1]+xa[2])/2,y=(ya[1]+ya[2])/2;
	if(x+y>=xb[1]+(yb[1]+yb[2])/2&&x+y<=xb[2]+(yb[1]+yb[2])/2&&y-x>=(yb[1]+yb[2])/2-xb[2]&&y-x<=(yb[1]+yb[2])/2-xb[1])
	{
		printf("YES");
		return 0;	
	}
	printf("NO");
	return 0;
}