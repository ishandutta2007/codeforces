#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int n,k,a[200005],f[200005];
char ch;
struct node{
	int id,num;
	bool operator <(const node &a)const{
		return a.num<num;
	}
};
priority_queue <node>h;
signed main(){
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>ch,a[i]=ch-'0'; 
	node c;
	c.num=c.id=0;
	for (int i=1;i<=n;i++){
		f[i]=f[i-1]+i;
		while(!h.empty()&&h.top().id<i-k)h.pop();
		if (!h.empty())f[i]=min(f[i],h.top().num);
		if (a[i]){
			int s=i+f[max(i-k-1,0ll)];
			if (!h.empty())s=min(s,i+h.top().num);
			c.num=s;
			c.id=i;
			h.push(c);
			f[i]=min(f[i],s);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}

//f[i]=max(i+f[i-1],j+f[max(j-k-1),0]);(j>=i-k)