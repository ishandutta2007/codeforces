#include<bits/stdc++.h>

using namespace std;

const int maxn=400005;

struct P{
	bool ia,ib;
	int v;
};

bool cmp(pair<long long,int> a,pair<long long,int> b){
	return a.first>b.first;
}

bool cm2(long long a,long long b){
	
	return a>b;
}

P p[maxn];
int n;

long long ans=0;
int cnt=0;
pair<long long,int> c01[maxn],c10[maxn];
long long l[maxn];
int ll;
int c01l,c10l;
bool vis[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char _[10];
		cin>>_>>p[i].v;
		p[i].ia=_[0]-'0';
		p[i].ib=_[1]-'0';
	}
	for(int i=1;i<=n;i++){
		if(p[i].ia&&p[i].ib){
			cnt++;
			ans+=p[i].v;
			vis[i]=1;
		}
		if(p[i].ia&&(!p[i].ib)){
			c10[c10l].first=p[i].v;
			c10[c10l++].second=i;
		}
		if(p[i].ib&&(!p[i].ia)){
			c01[c01l].first=p[i].v;
			c01[c01l++].second=i;
		}
	}
	sort(c01,c01+c01l,cmp);
	sort(c10,c10+c10l,cmp);
	for(int i=0;i<min(c01l,c10l);i++){
		vis[c01[i].second]=1;
		vis[c10[i].second]=1;
		ans+=c10[i].first+c01[i].first;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			l[ll++]=p[i].v;
		}
	}
	sort(l,l+ll,cm2);
	for(int i=0;i<min(ll,cnt);i++){
		ans+=l[i];
	}
	cout<<ans;
	return 0;
}