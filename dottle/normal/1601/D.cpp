#include<bits/stdc++.h>
const int N=1050000;
using namespace std;

struct node{
	int a,p;
	bool operator<(node b){
		return make_pair(max(a,p),p)<make_pair(max(b.a,b.p),b.p);
	}
}e[N];

int main(){
	int n,d,ans=0;cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>e[i].p>>e[i].a;
	sort(e+1,e+1+n);
	for(int i=1;i<=n;i++)
		if(d<=e[i].p)
			d=max(e[i].a,d),ans++;
	cout<<ans<<endl;
}