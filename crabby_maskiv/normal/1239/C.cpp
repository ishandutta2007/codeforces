#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
ll k;
pair<ll,int> p[N];
ll a[N];
int d[N];
priority_queue<int,vector<int> , greater<int> > w;//waiting
queue<int> q;//tank
ll ans[N];
bool check(int u){
	int ret=0;
	for(;u;u-=lbt(u)) ret+=d[u];
	return ret==0;
}
void change(int u,int x){
	for(;u<=n;u+=lbt(u)) d[u]+=x;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>p[i].first;
		p[i].second=i;
	}
	sort(p+1,p+n+1);
	int pos=1;
	p[n+1].first=0x3f3f3f3f3f3f3f3fll;
	while(pos<=n||!q.empty()){
		if(!q.empty()&&ans[q.front()]<p[pos].first){
			int u=q.front();q.pop();
			change(u,-1);
			while(!w.empty()){
				int v=w.top();
				if(check(v)){
					if(q.empty()) ans[v]=ans[u]+k;
					else ans[v]=ans[q.back()]+k;
					q.push(v);
					change(v,1);
					w.pop();
				}
				else break;
			}
			cout<<endl;
		}
		else{
			int u=p[pos].second;
			ll t=p[pos].first;
			pos++;
			if(check(u)){
				if(q.empty()) ans[u]=t+k;
				else ans[u]=ans[q.back()]+k;
				q.push(u);
				change(u,1);
			}
			else w.push(u);
		}
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}