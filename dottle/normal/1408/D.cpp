#include<bits/stdc++.h>
//#define int long long
const int N=1.1e6;
using namespace std;

struct node{
	int x,y;
	void input(){cin>>x>>y;}
}t[N],l[N];

int n,m,ans[N],res=1e9;

void updt(node x,node y){
	if(x.x>y.x||x.y>y.y)return;
	ans[y.x-x.x]=max(ans[y.x-x.x],y.y-x.y+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)t[i].input();
	for(int i=1;i<=m;i++)l[i].input();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			updt(t[i],l[j]);
	for(int i=N-2;~i;i--)
		ans[i]=max(ans[i],ans[i+1]),res=min(res,ans[i]+i);
	cout<<res;
}