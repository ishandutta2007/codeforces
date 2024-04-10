#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;

char chicken(int x){
	if(x<=9) return char(48+x);
	if(x<=35) return char(55+x);
	return char(61+x);
}

pii f(pii x, int r){
	pii y;
	if(x.first%2==0){
		if(x.second==r-1){
			y.first=x.first+1;
			y.second=r-1;
			return y;
		}
		y.first=x.first;
		y.second=x.second+1;
		return y;
	}
	if(x.first%2==1){
		if(x.second==0){
			y.first=x.first+1;
			y.second=0;
			return y;
		}
		y.first=x.first;
		y.second=x.second-1;
		return y;
	}
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int c,r,k;
		cin >> c >> r >> k;
		char a[c][r];
		int rice=0;
		loop(c){
			loopi(j,r){
				cin >> a[i][j];
				if(a[i][j]=='R') rice++;
			}
		}
		int num;
		char ans[c][r];
		pii x;
		x.first=x.second=0;
		loop(k){
			if(i<rice%k) num=rice/k+1;
			else num=rice/k;
			while(1){
				if(a[x.first][x.second]=='R'){
					if(num==0) break;
					num--;
				}
				ans[x.first][x.second]=chicken(i);
				x=f(x,r);
				if(x.first>=c) break;
			}
			if(x.first>=c) break;
		}
		loop(c){
			loopi(j,r){
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}