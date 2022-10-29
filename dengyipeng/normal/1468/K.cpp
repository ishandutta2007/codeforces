#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
//#define file
using namespace std;

int T,n,i,j,k,l;
int X[5001],Y[5001];
int x,y,lx,ly;
char st[5001];

void Move(char ch)
{
	switch (ch)
	{
		case 'U':{++y;break;}
		case 'D':{--y;break;}
		case 'L':{--x;break;}
		case 'R':{++x;break;}
	}
}

int main()
{
	#ifdef file
	freopen("k.in","r",stdin);
	#endif
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%s",st+1);n=strlen(st+1);x=y=0;
		fo(i,1,n) Move(st[i]),X[i]=x,Y[i]=y;
		fo(i,1,n)
		if (X[i] || Y[i])
		{
			x=y=0;
			fo(j,1,n)
			{
				lx=x,ly=y;
				Move(st[j]);
				if (x==X[i] && y==Y[i]) x=lx,y=ly;
			}
			if (!x && !y) {printf("%d %d\n",X[i],Y[i]);break;}
		}
		if (i>n) printf("0 0\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}