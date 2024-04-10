#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define MAXN 200000
#define MAXL 29
struct node{int w,l,r;}t[MAXL*MAXN+5];
int tn=2;
void change(int x,int w)
{
	int k=1,i;
	for(i=MAXL;i>=0;i--)
		if(x&(1<<i))t[k=t[k].l?t[k].l:(t[k].l=tn++)].w+=w;
		       else t[k=t[k].r?t[k].r:(t[k].r=tn++)].w+=w;
}
int query(int x)
{
	int k=1,i;
	for(i=MAXL;i>=0;i--)
		if(x&(1<<i))
			if(t[t[k].r].w)k=t[k].r;
			else{k=t[k].l;x^=(1<<i);}
		else
			if(t[t[k].l].w){k=t[k].l;x^=(1<<i);}
			else k=t[k].r;
	return x;
}
int main()
{
	int q,x;char c;
	change(0,1); 
	read(q);
	while(q--)
	{
		do c=getchar();while(c!='+'&&c!='-'&&c!='?');
		read(x);
		if(c=='+')change(x,1);
		if(c=='-')change(x,-1);
		if(c=='?')printf("%d\n",query(x));
	}
}