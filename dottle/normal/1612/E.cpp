#include<bits/stdc++.h>
const int N=205000;
using namespace std;

int a[N],b[N],v[N];
int n,m;
double ans;
vector<int>res;
double p[N];

void solve(int k){
	if(k>m)return ;
	double na=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
		p[a[i]]+=min(1.,1.*v[i]/k);
	vector<int> id(m);for(int i=0;i<m;i++)id[i]=i+1;
	sort(id.begin(),id.end(),[](int x,int y){return p[x]>p[y];});
	for(int i=0;i<k;i++)
		na+=p[id[i]];
	if(na>ans){
		ans=na;
		res.clear();
		for(int i=0;i<k;i++)res.push_back(b[id[i]]);
	}
}

void solve2(){
	if(m<=20)return ;
	double na=0;
	int mx=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
		p[a[i]]+=v[i];
	vector<int> id(m);for(int i=0;i<m;i++)id[i]=i+1;
	sort(id.begin(),id.end(),[](int x,int y){return p[x]>p[y];});
	for(int i=0,s=0;i<m;i++){
		s+=v[i];
		if(1.*s/(i+1)>na)na=1.*s/(i+1),mx=i+1;
	} 
	if(na>ans){
		res.clear();
		for(int i=0;i<mx;i++)res.push_back(b[id[i]]);
	}
}

void print(){
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x<<' ';
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>v[i],b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	for(int i=1;i<=20;i++)
		solve(i);
	solve2();
	print();
}