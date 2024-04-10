#include<bits/stdc++.h>
#define int long long
const int N=500050;
using namespace std;

int n,a[N],t,s;

struct node{int x,y,z;};
queue<node>q;

void print(){
	cout<<q.size()<<endl;
	while(q.size())
		cout<<q.front().x<<' '<<q.front().y<<' '<<q.front().z<<endl,
		q.pop();
}

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n,s=0;
		for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
		if(s%n){
			cout<<-1<<endl;
			continue;
		}
		for(int i=2;i<=n;i++)
			q.push({1,i,(i-a[i]%i)%i}),q.push({i,1,(a[i]+i-1)/i});
		for(int i=2;i<=n;i++)
			q.push({1,i,s/n});
		print();
	}
}