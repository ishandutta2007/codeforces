#include<bits/stdc++.h>
using namespace std;
struct segment{
	double l,r,k,b;
};
vector<segment>s,t;
int n,q,a,b,x[6003];
double add(int X){
	t.clear();
	bool fnd=0;
	double ret=q;
	for(int i=0;i<s.size();i++){
		double nw=(-s[i].b)/s[i].k;
		if(s[i].l<=nw&&nw<=s[i].r&&!fnd||(i==0||s[i-1].k*s[i].l+s[i-1].b<0)&&s[i].k*s[i].l+s[i].b>0){
			fnd=1;
			if(nw>s[i].r||nw<s[i].l)
				nw=s[i].l;
			ret=nw;
			if(s[i].l!=nw)
				t.push_back({s[i].l,nw,s[i].k,s[i].b});
			t.push_back({nw,nw+b,0,0});
			if(s[i].r!=nw)
				t.push_back({nw+b,s[i].r+b,s[i].k,s[i].b-b*s[i].k});
		}else
			if(!fnd)
				t.push_back(s[i]);
			else
				t.push_back({s[i].l+b,s[i].r+b,s[i].k,s[i].b-b*s[i].k});
	}
	while(t.back().l>=q)
		t.pop_back();
	t.back().r=q;
	for(int i=0;i<t.size();i++)
		t[i].k+=2,t[i].b-=2*X;
	s=t;
	return ret;
}
double minn[6003],ans[6003],sum;
int main(){
	scanf("%d%d%d%d",&n,&q,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%d",x+i);
		x[i]=x[i]-a*i-1;
	}
	b-=a;q=q-a*(n-1)-1;
	s.push_back({0,q,2,-2*x[0]});
	for(int i=1;i<n;i++)
		minn[i-1]=add(x[i]);
	ans[n-1]=add(0);
	for(int i=n-2;i>=0;i--)
		if(ans[i+1]<minn[i])
			ans[i]=ans[i+1];
		else
			if(ans[i+1]>=minn[i]+b)
				ans[i]=ans[i+1]-b;
			else
				ans[i]=minn[i];
	for(int i=0;i<n;i++){
		sum+=(ans[i]-x[i])*(ans[i]-x[i]);
		printf("%.9lf ",ans[i]+1+i*a);
	}printf("\n%.9lf",sum);
}