#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1<<11;
int n, c, z, cnt, a[15], b[N], ans[N];
int ask(int x, int y){
	cout<<"? "<<x+1<<' '<<y+1<<endl;
	int t;
	cin>>t;
	return t;
}
int main() {
	ll seed=chrono::system_clock().now().time_since_epoch().count();
	mt19937 rng(seed);
	cin>>n;
	int x=0, now=N-1;
	for(int i=1; i<n; ++i){
		int t=ask(i, x);
		if((now&t)==t){
			if(t<now) a[cnt++]=x;
			x=i, now=t;
		}
	}
	a[cnt++]=x;
	for(int i=0; i<cnt; ++i){
		int c=0, s=N-1;
		for(int j=0; j<n; ++j) if(j!=a[i]) b[c++]=j;
		shuffle(b, b+c, rng);
		for(int j=0; j<c && j<14; ++j) s&=ask(a[i], b[j]);
		if(!s){ z=a[i]; break;}
	}
	for(int i=0; i<n; ++i) ans[i]=(i==z?0:ask(z, i));
	cout<<"!";
	for(int i=0; i<n; ++i) cout<<' '<<ans[i];
	cout<<endl;
	return 0;
}