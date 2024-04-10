#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,sx,sy;
	cin >> n >> sx >> sy;
	int x[n],y[n];
	loop(n) cin >> x[i] >> y[i];
	int u,d,l,r;
	u=d=l=r=0;
	loop(n){
		if(y[i]>sy) u++;
		if(y[i]<sy) d++;
		if(x[i]>sx) r++;
		if(x[i]<sx) l++;
	}
	char c;
	int Max=-1;
	if(u>Max&&sy<int(1e9)){
		Max=u;
		c='u';
	}
	if(d>Max&&sy>0){
		Max=d;
		c='d';
	}
	if(r>Max&&sx<int(1e9)){
		Max=r;
		c='r';
	}
	if(l>Max&&sx>0){
		Max=l;
		c='l';
	}
	cout << Max << "\n";
	if(c=='u') cout << sx << " " << sy+1 << "\n";
	if(c=='d') cout << sx << " " << sy-1 << "\n";
	if(c=='r') cout << sx+1 << " " << sy << "\n";
	if(c=='l') cout << sx-1 << " " << sy << "\n";
	return 0;
}