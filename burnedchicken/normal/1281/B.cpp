#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
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
	int t;
	cin >> t;
	string str1,str2,str3;
	int x,y;
	while(t--){
		cin >> str1 >> str2;
		str3=str1;
		sort(all(str3));
		x=y=-1;
		rep(str1.size()){
			if(str3[i]!=str1[i]){
				x=i;
				break;
			}
		}
		rep(str1.size()){
			if(str1[str1.size()-1-i]==str3[x]){
				y=str1.size()-1-i;
				break;
			}
		}
		if(x>=0) swap(str1[x],str1[y]);
		if(str1<str2) cout << str1 << "\n";
		else cout << "---\n";
	}
	return 0;
}