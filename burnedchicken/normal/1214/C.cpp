#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,x;
	string str;
	cin >> n >> str;
	x=0;
	loop(n){
		if(str[i]=='(') x++;
		else x--;
		if(x<=-2){
			cout << "No\n";
			return 0;
		}
	}
	if(x==0) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}