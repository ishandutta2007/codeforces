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
	int q;
	cin >> q;
	string str1,str2;
	bool a[26],b[26],ok;
	loopi(noob,q){
		cin >> str1 >> str2;
		loop(26) a[i]=b[i]=false;
		loop(str1.size()){
			a[str1[i]-'a']=true;
			b[str2[i]-'a']=true;
		}
		ok=false;
		loop(26) if(a[i]&&b[i]) ok=true;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}