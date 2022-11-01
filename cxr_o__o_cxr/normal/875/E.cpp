#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,s1,s2,a[N];
inline bool check(int mx){
	set<int>s;
	s.insert(s1);s.insert(s2);
	for(int i=1;i<=n;i++){
		while(!s.empty()&&abs(a[i]-*s.begin())>mx)s.erase(s.begin());
		while(!s.empty()&&abs(a[i]-*prev(s.end()))>mx)s.erase(prev(s.end()));
		if(s.empty())return 0;
		s.insert(a[i]); 
	}
	return 1;
} 
int main(){
	n=read();s1=read();s2=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=abs(s1-s2),r=1000000000,mid;//l!
	while(l<r){
		mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r;
	return (0-0);
}