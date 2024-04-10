#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int main(){
    int i,j;
    int T;cin>>T;
    while(T--){
    	ll x,y,z;
    	cin>>x>>y>>z;
    	ll sum=x+y+z;
    	cout<<min(min(x,y),sum/3)<<endl;
	}
    return 0;
}