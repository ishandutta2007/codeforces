#include<bits/stdc++.h>
#define LL long long
using namespace std;
int mar,res,p1,q1,m1,p2,q2,m2;bool usd[10];
int calc(int n,int p1,int q1,int m1,int p2,int q2,int m2){
	int t=min(p1,q2),res=0;
	p1-=t;q2-=t;res+=t;
	t=min(q1,m2);
	q1-=t;m2-=t;res+=t;
	t=min(m1,p2);
	m1-=t;p2-=t;res+=t;
	return res;
}
void dfs(int dep){
	//printf("dep:%d %d\n",dep,res);
	if(dep>6){mar=max(mar,res);return;}
	int t;
	if(!usd[1]){
		t=min(p1,p2);p1-=t;p2-=t;res+=t;
		usd[1]=true;dfs(dep+1);usd[1]=false;
		p1+=t;p2+=t;res-=t;
	}
	if(!usd[2]){
		t=min(q1,q2);q1-=t;q2-=t;res+=t;
		usd[2]=true;dfs(dep+1);usd[2]=false;
		q1+=t;q2+=t;res-=t;
	}
	if(!usd[3]){
		t=min(m1,m2);m1-=t;m2-=t;res+=t;
		usd[3]=true;dfs(dep+1);usd[3]=false;
		m1+=t;m2+=t;res-=t;
	}
	if(!usd[4]){
		t=min(p1,q2);p1-=t;q2-=t;res+=t;
		usd[4]=true;dfs(dep+1);usd[4]=false;
		p1+=t;q2+=t;res-=t;
	}
	if(!usd[5]){
		t=min(q1,m2);q1-=t;m2-=t;res+=t;
		usd[5]=true;dfs(dep+1);usd[5]=false;
		q1+=t;m2+=t;res-=t;
	}
	if(!usd[6]){
		t=min(m1,p2);m1-=t;p2-=t;res+=t;
		usd[6]=true;dfs(dep+1);usd[6]=false;
		m1+=t;p2+=t;res-=t;
	}
}
int main(){
	int n,ans,t;
	scanf("%d",&n);scanf("%d%d%d%d%d%d",&p1,&q1,&m1,&p2,&q2,&m2);
	ans=calc(n,p1,q1,m1,p2,q2,m2);
	//if(m2>p1)m2-=p1,p1=0,res+=p1;
	//else p1-=m2,m2=0,res+=m2;
	
	swap(p1,p2);swap(q1,q2);swap(m1,m2);
	res=0;dfs(1);
	printf("%d %d\n",n-mar,ans);
	return 0;
}