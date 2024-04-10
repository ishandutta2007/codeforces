#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
const int N=2e5+50;
int n,m,a[N],t1[210],t2[210],lo;
void add(int x,int val){
	for(;x<=200;x+=lowbit(x))t1[x]+=val,t2[x]++;
}
int ask(int val){
	int x=0,now=0,ans=0;bool flag=0;
	for(int i=1<<lo;i;i>>=1){
		if(now+t1[x+i]<val)x+=i,now+=t1[x],ans+=t2[x];
		else flag=1;
	}
//	if(val==10)printf("%d -----",x);
	if(flag)ans+=(val-now)/(x+1);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);lo=log2(100);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		printf("%d ",i-1-ask(m-a[i]));
		add(a[i],a[i]);
	}
	return 0;
}
//7 15
//1 10 5 4 5 6 3