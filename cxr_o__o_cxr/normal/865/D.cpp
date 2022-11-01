#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=3e5+4;
priority_queue<int>q;
signed main(){
	int n=read(),ans=0;
	for(int i=1,x;i<=n;i++){
		x=read();
		if(!q.empty()&&x+q.top()>0){
			ans+=x+q.top();
			q.pop();
			q.push(-x);
		}
		q.push(-x);
	}
	cout<<ans;
	return (0-0);
}