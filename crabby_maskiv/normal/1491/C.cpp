#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int n,m;
int s[N];
int v[N],len;
int fa[N],mx[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
inline void merge(int x,int y){
	x=rt(x);y=rt(y);
	if(x==y) return;
	mx[x]=max(mx[x],mx[y]);
	fa[y]=x;
}
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>s[i];
		for(i=1;i<=n;i++) fa[i]=mx[i]=i;
		ll ans=0;
		for(i=1;i<n;i++)
			if(s[i]==1&&s[i+1]==1) merge(i,i+1);
		for(i=1;i<=n;i++){
			if(i==n){
				ans+=s[i]-1;
				break;
			}
			if(i+s[i]>n){
				ans+=i+s[i]-n;
				s[i]=n-i;
			}
			while(s[i]>1){
				ans++;len=0;
				for(j=i;j<=n;){
					v[++len]=j;
					if(s[j]==1) j=mx[rt(j)]+1;
					else j+=s[j];
				}
				for(j=1;j<=len;j++){
					s[v[j]]=max(s[v[j]]-1,1);
					if(s[v[j]]==1){
						if(s[v[j]-1]==1) merge(v[j]-1,v[j]);
						if(s[v[j]+1]==1) merge(v[j]+1,v[j]);
					}
				}
			}
		}
		for(i=1;i<=n;i++) s[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}