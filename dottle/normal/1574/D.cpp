#include<bits/stdc++.h>
//#define int long long
const int N=500050;
using namespace std;

int n,A[11][N],c[N],m;

struct node{
	int a[11],s;
	void upd(){
		s=0;
		for(int i=1;i<=n;i++)
			s+=A[i][a[i]];
	}
	bool operator <(const node&b)const{
		if(s!=b.s)
			return s<b.s;
		for(int i=1;i<=n;i++)
			if(a[i]!=b.a[i])
				return a[i]<b.a[i];
		return 0;
	}
	void input(){
		for(int i=1;i<=n;i++)
			cin>>a[i];
	}
	void output(){
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		exit(0);
	}
}e,nw;
map<node,int> a,b;
priority_queue<node>q; 

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++)
			cin>>A[i][j];
		e.a[i]=c[i];
	}
	e.upd();
	cin>>m;
	for(int i=1;i<=m;i++)
		nw.input(),nw.upd(),a[nw]=1;
	q.push(e);
	b[e]=1;
	while(1){
		node nw=q.top();q.pop();
		if(!a[nw])nw.output();
		for(int i=1;i<=n;i++){
			node n2=nw;
			n2.a[i]--,n2.upd();
			if(n2.a[i]>0&&!b[n2])q.push(n2),b[n2]=1;
		}
	}
}