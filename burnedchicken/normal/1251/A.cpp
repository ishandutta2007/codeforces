#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const int mod=1e9+7;
const int maxn=200005;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,cnt;
	cin >> t;
	string str;
	bool ans[26];
	loop(26) ans[i]=false;
	loopi(j,t){
		cin >> str;
		if(str.size()==1){
			cout << str[0] << "\n";
			continue;
		}
		cnt=0;
		loop(26) ans[i]=false;
		str+=' ';
		loop(str.size()){
			cnt++;
			if(str[i]!=str[i+1]){
				if(cnt%2==1) ans[str[i]-97]=true;
				cnt=0;
			}
		}
		loop(26) if(ans[i]) cout << char('a'+i);
		cout << "\n";
	}
	return 0;
}