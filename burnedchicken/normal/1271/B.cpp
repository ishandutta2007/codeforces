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
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> ans;
	int x=0;
	loop(n) if(str[i]=='B') x++;
	if(n%2==0&&x%2==1){
		cout << "-1\n";
		return 0;
	}
	if(n%2==1&&x%2==1){
		loop(n-1){
			if(str[i]=='W'){
				str[i]='B';
				if(str[i+1]=='B') str[i+1]='W';
				else str[i+1]='B';
				ans.push_back(i);
			}
		}
	}
	else{
		loop(n-1){
			if(str[i]=='B'){
				str[i]='W';
				if(str[i+1]=='B') str[i+1]='W';
				else str[i+1]='B';
				ans.push_back(i);
			}
		}
	}
	cout << ans.size() << "\n";
	loop(ans.size()) cout << ans[i]+1 << " ";
	cout << "\n";
	return 0;
}