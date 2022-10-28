#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
char s[N],t[N];
int n,a[N];
void add(int x,int y){
	for(;x<=n;x+=x&-x)a[x]+=y;
}
int sum(int x){
	int r=0;
	for(;x;x-=x&-x)r+=a[x];
	return r;
}
queue<int>q[199];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k,l,r,m,x;
	long long ans,cnt;
	for(cin>>T;T--;){
		cin>>n>>s+1>>t+1;ans=1e18,cnt=0;
		for(i=1;i<=n;++i)a[i]=0;
		for(i=1;i<=n;++i)add(i,1);
		for(i=0;i<190;++i){
			while(q[i].size())q[i].pop();
		}
		for(i=1;i<=n;++i){
			q[s[i]].push(i);
		}
		for(i=1;i<=n;++i){
			x=N;
			for(j='a';j<t[i];++j){
				if(q[j].size())x=min(x,q[j].front()); 
			}
			if(x<N){
				ans=min(ans,cnt+sum(x-1));
			}
			if(q[t[i]].size()){
				x=q[t[i]].front(),q[t[i]].pop();
				cnt+=sum(x-1),add(x,-1);
			}else break;
		}
		if(ans>1e16)cout<<-1<<'\n';else cout<<ans<<'\n';
	}
	return 0;
}