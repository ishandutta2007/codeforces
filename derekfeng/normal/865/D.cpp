#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
priority_queue<int,vector<int>,greater<int> >p,q;
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		int add=0,z=0;
		if(!p.empty()&&x-p.top()>add)z=1,add=x-p.top();
		if(!q.empty()&&x-q.top()>add)z=2,add=x-q.top();
		ans+=add;
		if(z==0)p.push(x);
		if(z==1)q.push(x),p.pop();
		if(z==2)q.push(x),p.push(q.top()),q.pop();
	}
	printf("%lld",ans);
}