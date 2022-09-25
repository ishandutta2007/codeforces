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
		vector<int> ans;
		ans.clear();
		int x=1;
		while(!str.empty()){
			if(str.substr(0,5)=="twone"){
				ans.push_back(x+2);
				str.erase(str.begin(),str.begin()+5);
				x+=5;
			}
			else if(str.substr(0,3)=="one"||str.substr(0,3)=="two"){
				ans.push_back(x+1);
				str.erase(str.begin(),str.begin()+3);
				x+=3;
			}
			else{
				str.erase(str.begin());
				x++;
			}
		}
		cout << ans.size() << "\n";
		loop(ans.size()) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}