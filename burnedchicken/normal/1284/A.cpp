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
	int n,m;
	cin >> n >> m;
	string str1[n];
	string str2[m];
	loop(n) cin >> str1[i];
	loop(m) cin >> str2[i];
	int q,y;
	cin >> q;
	loopi(noob,q){
		cin >> y;
		cout << str1[(y-1)%n] << str2[(y-1)%m] << "\n";
	}
	return 0;
}