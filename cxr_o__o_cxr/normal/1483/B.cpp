//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,las,a[N],L[N],R[N];
set<int>s;
vector<int>ans;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
inline void insert(int x,int fl){
	if(gcd(a[L[x]],a[x])==1){
		if(fl)s.insert(x);
		else s.erase(x);
	}
}
inline void solve(){
	s.clear();
	ans.clear();
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		L[i]=i-1;R[i]=i+1;
	}
	L[1]=n;R[n]=1;
	for(int i=1;i<=n;i++)insert(i,1);
	las=1;
	while(!s.empty()&&n){
		auto it=s.upper_bound(las);
		if(it==s.end())it=s.begin();
		las=*it;
		ans.push_back(las);
		s.erase(las);
		insert(R[las],0);
		L[R[las]]=L[las];R[L[las]]=R[las];
		insert(R[las],1);
		las=R[las];
		n--;
	}
	cout<<ans.size()<<" ";
	for(auto v:ans)cout<<v<<" ";puts("");
}
int main(){
	for(int T=read();T--;)solve();
	return (0-0);
}