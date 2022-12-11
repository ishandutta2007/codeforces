#include<bits/stdc++.h>
using namespace std;
char b[5];int d[200];
struct node{
	int x;char c;
	bool friend operator <(node a,node b){
		if(d[a.c]==d[b.c])return a.x<b.x;
		return d[a.c]<d[b.c];
	}
}a[5];
int main(){
	d['m']=1;d['s']=2;d['p']=3;
	for(int i=1;i<=3;i++){
		scanf("%s",b);
		a[i].x=b[0]-'0';a[i].c=b[1];
	}
	sort(a+1,a+4);
	if(a[1].c!=a[2].c&&a[2].c!=a[3].c)putchar('2'),exit(0);
	if(a[1].c==a[2].c&&a[2].c==a[3].c){
		if(a[1].x==a[2].x&&a[2].x==a[3].x)putchar('0'),exit(0);
		if(a[1].x==a[2].x-1&&a[2].x==a[3].x-1)putchar('0'),exit(0);
	}
	if(a[1].c==a[2].c&&(a[1].x==a[2].x-1||a[1].x==a[2].x||a[1].x==a[2].x-2))putchar('1'),exit(0);
	if(a[2].c==a[3].c&&(a[2].x==a[3].x-1||a[2].x==a[3].x||a[2].x==a[3].x-2))putchar('1'),exit(0);
	putchar('2');
	return 0;
}
//3p 4p 2s