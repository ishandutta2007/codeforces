#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int tt,n,m,i,j,fa[25];
string s,t;
int fnd(int x){
	if(x==fa[x]) return x;
	return fa[x]=fnd(fa[x]);
}
set<pair<char,char> > ss;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tt;
	while(tt--){
		cin>>n>>s>>t;
		rep(i,20)fa[i]=i;
		s=" "+s;t=" "+t;
		int ans=0;//ss.clear();
		rep(i,n){
			if(s[i]<t[i]){
				fa[fnd(s[i]-'a'+1)]=fnd(t[i]-'a'+1);
			}
			else if(s[i]>t[i]){
				ans=-1;break;
			}
		}
		if(ans==-1){
			puts("-1");
			continue;
		}
		rep(i,20){
			ans+=(fnd(i)!=i);
		}
		printf("%d\n",ans);
	}
	return 0;
}