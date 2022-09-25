#include <bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))

using namespace std;

const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin >> n >> k;
	char c[n];
	loop(n) cin >> c[i];
	char x[n];
	loop(k) x[i]=c[i];
	loop(n-k) x[i+k]=x[i];
	bool ok=true;
	loop(n){
		if(c[i]<x[i]) break;
		if(c[i]>x[i]){
			ok=false;
			break;
		}
	}
	int y=k-1;
	if(!ok){
		while(1){
			if(x[y]=='9'){
				x[y]='0';
				y--;
			}
			else{
				x[y]++;
				break;
			}
		}
		loop(n-k) x[i+k]=x[i];
	}
	cout << n << "\n";
	loop(n) cout << x[i];
	cout << "\n";
	return 0;
}