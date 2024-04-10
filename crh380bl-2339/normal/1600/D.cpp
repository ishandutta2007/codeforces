#include<bits/stdc++.h>
#define ll long long
#define N 1000000000
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	return z;
}
int main(){
	int a=ask(1,1),b=ask(1,N),c=ask(N,1),d,x,y,p,q;
	a+=2;
	b-=N-1;
	c-=N-1;
	x=1+ask(1,(a-b+1)/2);
	y=a-x;
	q=x-b;
	p=y-c;
	printf("! %d %d %d %d\n",x,y,p,q);
	return 0;
}