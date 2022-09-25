#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

struct point{
	ll x,y,z,pos;
};

bool comp(point p1, point p2){
	if(p1.x!=p2.x) return p1.x<p2.x;
	if(p1.y!=p2.y) return p1.y<p2.y;
	if(p1.z!=p2.z) return p1.z<p2.z;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,it,l;
	cin >> n;
	point a[n];
	loop(n) cin >> a[i].x >> a[i].y >> a[i].z;
	loop(n) a[i].pos=i+1;
	sort(a,a+n,comp);
	it=0;
	vector<ll> vec1,vec2;
	while(it<n-1){
		if(a[it].x==a[it+1].x&&a[it].y==a[it+1].y){
			cout << a[it].pos << " " << a[it+1].pos << endl;
			it=it+2;
		}
		else{
			vec1.push_back(it);
			it++;
		}
	}
	if(it==n-1) vec1.push_back(it);
	it=0;
	l=vec1.size();
	while(it<l-1){
		if(a[vec1.at(it)].x==a[vec1.at(it+1)].x){
			cout << a[vec1.at(it)].pos << " " << a[vec1.at(it+1)].pos << endl;
			it=it+2;
		}
		else{
			vec2.push_back(vec1.at(it));
			it++;
		}
	}
	if(it==l-1) vec2.push_back(vec1.at(it));
	it=0;
	l=vec2.size();
	while(it<l-1){
		cout << a[vec2.at(it)].pos << " " << a[vec2.at(it+1)].pos << endl;
		it=it+2;
	}
	return 0;
}