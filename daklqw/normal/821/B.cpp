#include <iostream>
#define ll long long
using namespace std;
inline ll get(ll x,ll y){return ((ll)x+1)*(y+1)*(x+y)/2;}
int m,b;ll ans=-0x7ffffffffffffff;
int main(){
	cin>>m>>b;
	for(int y=0;y<=b;y++)
		ans=max(ans,get(y,(b-y)*m));
	cout<<ans<<endl;
	return 0;
}