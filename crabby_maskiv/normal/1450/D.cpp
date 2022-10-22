#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m;
int a[N];
int pre[N],nxt[N];
int stk[N],top;
vector<int> v[N];
int ban[N];
int cnt[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		top=0;stk[0]=0;
		for(i=1;i<=n;i++){
			while(top&&a[stk[top]]>=a[i]) top--;
			pre[i]=stk[top];
			stk[++top]=i;
		}
		top=0;stk[0]=n+1;
		for(i=n;i;i--){
			while(top&&a[stk[top]]>=a[i]) top--;
			nxt[i]=stk[top];
			stk[++top]=i;
		}
		for(i=1;i<=n;i++) v[i].clear();
		for(i=1;i<=n;i++) ban[i]=cnt[i]=0;
		for(i=1;i<=n;i++)
			v[a[i]].push_back(i);
		for(i=1;i<=n;i++){
			int rgt=0,mx=0;
			set<pair<int,int> > st;
			for(auto x:v[i]){
				if(st.find({pre[x]+1,nxt[x]-1})!=st.end())
					rgt=max(rgt,nxt[x]-pre[x]-2);
				st.insert({pre[x]+1,nxt[x]-1});
				mx=max(mx,nxt[x]-pre[x]-1);
				if(x==pre[x]+1||x==nxt[x]-1) continue;
				rgt=max(rgt,nxt[x]-pre[x]-2);
			}
			int mx1=0,mx2=0;
			for(auto x:st){
				int w=x.second-x.first+1;
				if(w>=mx1){
					mx2=mx1;
					mx1=w;
				}
				else if(w>=mx2)
					mx2=w;
			}
			rgt=max(rgt,mx2);
			if(1<=rgt){
				ban[1]++;
				ban[rgt+1]--;
			}
			if(n-i+2<=mx){
				ban[n-i+2]++;
				ban[mx+1]--;
			}
		}
		for(i=1;i<=n;i++) ban[i]+=ban[i-1];
		for(i=1;i<=n;i++) cnt[a[i]]++;
		bool ans1=1;
		for(i=1;i<=n;i++) ans1=ans1&(cnt[i]==1);
		cout<<ans1;
		for(i=2;i<=n;i++) cout<<(ban[i]==0);
		cout<<endl;
	}
	return 0;
}