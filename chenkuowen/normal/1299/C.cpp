#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
typedef long long ll;
pair<ll,int> a[MAX_N];
int lst[MAX_N],nxt[MAX_N],n;
bool vis[MAX_N];
set<int> s;
void opera(int x){
	if(lst[x]!=0&&a[x].first*a[lst[x]].second
		<a[lst[x]].first*a[x].second)
		s.insert(x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		a[i]=make_pair(x,1);
		nxt[i]=i+1;
		lst[i]=i-1;
		if(i>1){
			if(a[i].first<a[i-1].first)
				s.insert(i);
		}
		vis[i]=1;
	}
	while(!s.empty()){
		int x=*s.begin(); s.erase(s.begin());
		a[x]=make_pair(a[lst[x]].first+a[x].first
			,a[lst[x]].second+a[x].second);
		vis[lst[x]]=0;
		lst[x]=lst[lst[x]]; 
		nxt[lst[x]]=x;
		opera(x);
		if(nxt[x]!=n+1) opera(nxt[x]);
	}
	for(int i=1;i<=n;++i)
		if(vis[i]){
			double key=(double)a[i].first/a[i].second;
			for(int j=1;j<=a[i].second;++j)
				printf("%.10lf\n",key);
		}
	return 0;
}