#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
ll x[4],y[4],X[4],Y[4];
vector<pair<ll,ll> >p;
ll dis(ll id1,ll id2,ll id3){
	abs(x[id2]-x[id1])+abs(y[id2]-y[id1])+abs(x[id3]-x[id2])+abs(y[id3]-y[id2]); 
}
void move(ll a,ll b,ll c,ll d){
	if(a!=c)p.push_back(make_pair(a,b)),
			p.push_back(make_pair(c,b));
	if(b!=d)p.push_back(make_pair(c,b)),
			p.push_back(make_pair(c,d));
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]); 
	For(i,1,3)X[i]=x[i],Y[i]=y[i];
	sort(X+1,X+4);
	sort(Y+1,Y+4);
	move(X[1],Y[2],X[3],Y[2]);
	if (y[1]!=Y[2])
		move(x[1],y[1],x[1],Y[2]);
	if (y[2]!=Y[2])
		move(x[2],y[2],x[2],Y[2]);
	if (y[3]!=Y[2])
		move(x[3],y[3],x[3],Y[2]);
	cout<<p.size()/2<<endl;
	for(int i=0;i<p.size();i+=2)cout<<p[i].first<<' '<<p[i].second<<' '<<p[i+1].first<<' '<<p[i+1].second<<endl; 
}