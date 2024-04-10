#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
struct C{ ll x,y; };
vector<C> a;
C s;
inline ll dis(C a,C b){
	return abs(b.x-a.x)+abs(b.y-a.y);
}
ll solve1(int x){
	ll cnt=dis(a[x],s),ret=1;
	if(cnt>t) return ret-1;
	for(int i=x-1;i>=0;--i){
		cnt+=dis(a[i+1],a[i]);
		++ret;
		if(cnt>t) return ret-1;
	}
	return ret;
}
ll solve2(int x){
	ll cnt=dis(a[x],s),ret=1;
	if(cnt>t) return ret-1;
	for(int i=x+1;i<a.size();++i){
		cnt+=dis(a[i-1],a[i]);
		++ret;
		if(cnt>t) return ret-1;
	}
	return ret;
}
int main(){
	ll x0,y0,ax,ay,bx,by,xs,ys; 
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>s.x>>s.y>>t;
	a.push_back((C){x0,y0});
	while(1){
		C e=a.back();
		a.push_back((C){ax*e.x+bx,ay*e.y+by});
		if(max(a.back().x,a.back().y)>(ll)2e16){
			a.pop_back();
			break;
		}
	}
	ll ans=0;
	for(int i=0;i<a.size();++i)
		ans=max({ans,solve1(i),solve2(i)});
	cout<<ans;
	return 0;
}