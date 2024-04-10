#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	string ans,str1,str2;
	if(a>b){
		if(c>0||d>0) cout << "NO\n";
		else if(a>b+1) cout << "NO\n";
		else{
			cout << "YES\n";
			ans="0";
			loop(b) ans+=" 1 0";
			cout << ans << "\n";
		}
		return 0;
	}
	if(d>c){
		if(a>0||b>0) cout << "NO\n";
		else if(d>c+1) cout << "NO\n";
		else{
			cout << "YES\n";
			ans="3";
			loop(c) ans+=" 2 3";
			cout << ans << "\n";
		}
		return 0;
	}
	loop(a) str1+="0 1 ";
	loop(d) str2+=" 2 3";
	b=b-a;
	c=c-d;
	if(abs(b-c)>1){
		cout << "NO\n";
		return 0;
	}
	if(b==c+1) ans+="1 ";
	ans+=str1;
	loop(min(b,c)) ans+="2 1 ";
	if(!ans.empty()) ans.erase(ans.end()-1,ans.end());
	ans+=str2;
	if(c==b+1) ans+=" 2";
	if(ans[0]==' ') ans.erase(ans.begin(),ans.begin()+1);
	cout << "YES\n" << ans << "\n";
	return 0;
}