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
	int q;
	cin >> q;
	loopi(noob,q){
		string str;
		cin >> str;
		if(str[str.size()-1]=='o') cout << "FILIPINO\n";
		else if(str[str.size()-1]=='u') cout << "JAPANESE\n";
		else cout << "KOREAN\n";
	}
	return 0;
}