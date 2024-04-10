#include<bits/stdc++.h>
const int N=200050;
using namespace std;

int n,p[N],cir[N],cnt,b[N];
queue<pair<int,int> >q;
void swp(int x,int y){
	swap(p[x],p[y]),q.push(make_pair(x,y));
}
void dcir(int x,int y){
	swp(x,y);
	while(p[x]^y)swp(p[x],x);
	while(p[y]^x)swp(p[y],y);
	swp(x,y);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=++cnt,cir[cnt]=i;
			for(int x=p[i];x^i;x=p[x])b[x]=cnt;
		}
	if(cnt==1){
		int a=1,b=p[1],c;
		while(p[p[a]]^a)
			swp(a,p[a]);
		c=p[a];
		swp(b,c),swp(a,c),swp(a,b);
	}else{
		for(int i=1;i<cnt;i+=2)dcir(cir[i],cir[i+1]);
		if(cnt&1)dcir(1,cir[cnt]);
	}
	cout<<q.size()<<endl;
	while(q.size())cout<<q.front().first<<' '<<q.front().second<<endl,q.pop();
}