#include<bits/stdc++.h>
using namespace std;
int T,n,m;
struct dat{int v,id;char s;}a[300004],a0[300004],a1[300004],tl[300004],tr[300004];
int ans[300004];
bool cmp(dat a,dat b){return a.v<b.v;}
void solve(dat *a,int n,int m){
	int lc=0,rc=0;
	stack<int>s;
	for(int i=1;i<=n;i++){
		if(a[i].s=='L'){
			if(!s.empty()){
				int x=s.top();
				int dis=(a[i].v-a[x].v)/2;
				ans[a[x].id]=ans[a[i].id]=dis;
				s.pop();
			}else tl[++lc]=a[i];
		}else s.push(i);
	}
	while(!s.empty()){
		tr[++rc]=a[s.top()];
		s.pop();
	}
	for(int i=1;i<lc;i+=2)ans[tl[i].id]=ans[tl[i+1].id]=(tl[i].v+tl[i+1].v)/2;
	for(int i=1;i<rc;i+=2)ans[tr[i].id]=ans[tr[i+1].id]=(m*2-tr[i].v-tr[i+1].v)/2;
	if((lc&1)&&(rc&1))ans[tl[lc].id]=ans[tr[rc].id]=(m*2-tr[rc].v+tl[lc].v)/2;
}
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].v,a[i].id=i,ans[i]=-1;
	for(int i=1;i<=n;i++)cin>>a[i].s;
	sort(a+1,a+n+1,cmp);
	int n0=0,n1=0;
	for(int i=1;i<=n;i++){
		if(a[i].v&1)a1[++n1]=a[i];
		else a0[++n0]=a[i];
	}
	solve(a0,n0,m),solve(a1,n1,m);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>T;
	while(T--)sol();
}