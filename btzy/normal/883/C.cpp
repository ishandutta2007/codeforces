#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f,T,t0,a[3],t[3],p[3];
void test(ll& best, int NUM1, int NUM2){
	//for(ll i=0;(i-1)*a[NUM1]<f;++i){
	for(ll ii=0;((ii-1)/a[NUM1]-1)*a[NUM1]<f;++ii){
		ll i=(ii-1)/a[NUM1]+1;
		ll bytes_left=f-ii;
		ll time_left=T-ii*t[NUM1];
		if(bytes_left<0){
			ll ime=time_left-bytes_left*t[NUM1];
			if(ime>=0){
				//cout<<'a' <<i<<endl;
				best=min(best,i*p[NUM1]);
			}
		}
		if(bytes_left<0||time_left<0)continue;
		ll c0;
		if(t0-t[NUM2]!=0)c0=(time_left-bytes_left*t[NUM2])/(t0-t[NUM2])+1;
		else c0=bytes_left;
		ll c2=(bytes_left-c0)/a[NUM2];
		c0=bytes_left-c2*a[NUM2];
		if(c2>=0&&c0>=0){
			if(t[NUM2]*c2*a[NUM2]+t0*c0<=time_left){
				//cout<<'b' <<i<<endl;
				best=min(best,i*p[NUM1]+c2*p[NUM2]);
			}
		}
		++c2;
		c0=bytes_left-c2*a[NUM2];
		if(c2>=0&&c0>=0){
			if(t[NUM2]*c2*a[NUM2]+t0*c0<=time_left){
				//cout<<'c' <<i<<endl;
				best=min(best,i*p[NUM1]+c2*p[NUM2]);
			}
		}
		c2=0;
		c0=bytes_left-c2*a[NUM2];
		if(c2>=0&&c0>=0){
			if(t[NUM2]*c2*a[NUM2]+t0*c0<=time_left){
				//cout<<'d' <<i<<endl;
				best=min(best,i*p[NUM1]+c2*p[NUM2]);
			}
		}
		c0=0;
		c2=(bytes_left-c0)/a[NUM2];
		c0=bytes_left-c2*a[NUM2];
		if(c2>=0&&c0>=0){
			if(t[NUM2]*c2*a[NUM2]+t0*c0<=time_left){
				//cout<<'e' <<i<<endl;
				best=min(best,i*p[NUM1]+c2*p[NUM2]);
			}
		}
		++c2;
		c0=bytes_left-c2*a[NUM2];
		if(c2>=0&&c0>=0){
			if(t[NUM2]*c2*a[NUM2]+t0*c0<=time_left){
				//cout<<'c' <<i<<endl;
				best=min(best,i*p[NUM1]+c2*p[NUM2]);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>f>>T>>t0>>a[1]>>t[1]>>p[1]>>a[2]>>t[2]>>p[2];
	ll best=numeric_limits<ll>::max();
	test(best,1,2);
	test(best,2,1);
	if(t0*f<=T)best=min(best,0ll);
	if(best==numeric_limits<ll>::max())cout<<-1<<endl;
	else cout<<best<<endl;
}