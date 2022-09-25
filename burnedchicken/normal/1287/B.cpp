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
	int n,k,ans=0;
	cin >> n >> k;
	string str[n];
	set<string> s;
	loop(n) cin >> str[i];
	loop(n) s.insert(str[i]);
	string str1;
	loop(n){
		loopii(j,i+1,n){
			str1.clear();
			loopi(l,k){
				if(str[i][l]==str[j][l]) str1.push_back(str[i][l]);
				else str1.push_back(char(int('S')+int('E')+int('T')-int(str[i][l])-int(str[j][l])));
			}
			if(s.count(str1)) ans++;
		}
	}
	cout << ans/3 << '\n';
	return 0;
}