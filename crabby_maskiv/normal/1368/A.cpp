#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x,y,z;cin>>x>>y>>z;
		if(x>y) swap(x,y);
		int cnt=0;
		while(x<=z&&y<=z){
			x+=y;cnt++;
			if(x>z) break;
			y+=x;cnt++;
			if(x>y) swap(x,y);
		}
		cout<<cnt<<endl;
	}
	return 0;
}