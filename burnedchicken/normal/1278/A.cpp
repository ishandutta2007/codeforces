#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;

bool equal(vector<int> vec1, vector<int> vec2){
	loop(vec1.size()){
		if(vec1[i]!=vec2[i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	string str1,str2;
	vector<int> a(26),ans(26);
	bool ok;
	loopi(noob,t){
		cin >> str1 >> str2;
		if(str2.size()<str1.size()){
			cout << "NO\n";
			continue;
		}
		loop(26) a[i]=ans[i]=0;
		loop(str1.size()) ans[str1[i]-'a']++;
		loop(str1.size()) a[str2[i]-'a']++;
		if(equal(a,ans)){
			cout << "YES\n";
			continue;
		}
		ok=false;
		loop(str2.size()-str1.size()){
			a[str2[str1.size()+i]-'a']++;
			a[str2[i]-'a']--;
			if(equal(a,ans)){
				cout << "YES\n";
				ok=true;
				break;
			}
		}
		if(!ok){
			cout << "NO\n";
			continue;
		}
	}
	return 0;
}