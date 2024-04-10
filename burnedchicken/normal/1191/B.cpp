#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	string str[3];
	rep(3) cin >> str[i];
	rep(3) reverse(str[i].begin(),str[i].end());
	sort(str,str+3);
	if(str[0]==str[1]&&str[1]==str[2]) cout << "0\n";
	else if(str[0]==str[1]||str[1]==str[2]) cout << "1\n";
	else if(str[0][0]==str[1][0]&&str[1][0]==str[2][0]&&str[0][1]+1==str[1][1]&&str[1][1]+1==str[2][1]) cout << "0\n";
	else if((str[0][0]==str[1][0]&&str[0][1]+1==str[1][1])||(str[1][0]==str[2][0]&&str[1][1]+1==str[2][1])) cout << "1\n";
	else if((str[0][0]==str[1][0]&&str[0][1]+2==str[1][1])||(str[1][0]==str[2][0]&&str[1][1]+2==str[2][1])) cout << "1\n";
	else cout << "2\n";
	return 0;
}