#include <bits/stdc++.h>
using namespace std;

const int N=500005;

int a[N],cnt,n,c[N],sum;
long long st[N],Ans;
priority_queue <long long ,vector<long long>,greater<long long > >  q;

bool cmp(int x,int y){
	return x>y;
}

void init(){
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i-1]) a[++cnt]=a[i],c[cnt]++;
		else c[cnt]++;	
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),Ans=Ans+a[i];
	init();
	for (int i=1;i<=cnt;i++){
		int top=0;
		int now=sum-q.size()*2;
		now=min(c[i],now);
		for (int j=1;j<=now;j++) st[++top]=a[i];
		now=min(sum,c[i])-now;
		for (int j=1;j<=now;j+=2){
			int x=q.top();q.pop();
			if (x<a[i]){
				st[++top]=a[i];
				if (j<now) st[++top]=a[i];
			}else{
				st[++top]=x;
				if (j<now && 2*a[i]>x) st[++top]=2*a[i]-x; 
			}
		}
		for (int j=1;j<=top;j++) q.push(st[j]);
		sum=sum+c[i];
	}
	while (!q.empty()){
		Ans=Ans-q.top();
		q.pop();
	}
	printf("%I64d\n",Ans);
}