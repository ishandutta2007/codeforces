#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,x,s2[N],r1,r2,tot,w1[N];char c[10];LL now,maxn;
void fail(){
	puts("OVERFLOW!!!");exit(0);
}
void add(){
	LL y=1;
	for(int i=1;i<=r2;i++){
		y*=s2[i];
		if(y>maxn)fail();
	}
	now+=y;
	if(now>maxn)fail();
}
int main(){
	scanf("%d",&n);
	maxn=(1ll<<32)-1;
	while(n--){
		scanf("%s",c);
		if(c[0]=='f'){
			scanf("%d",&x);tot++;
			if(x==1)w1[++r1]=tot;
			else s2[++r2]=x;
		}
		else if(c[0]=='a')add();
		else{
			if(w1[r1]==tot)r1--;
			else r2--;
			tot--;
		}
	}
	cout<<now;
	return 0;
}