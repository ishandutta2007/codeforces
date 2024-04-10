#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=200005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		string str;
		cin >> str;
		bool boo=true;
		if(str.size()==1){
			if(str[0]=='?') str[0]='a';
			cout << str << "\n";
			continue;
		}
		loop(str.size()){
			if(i==0){
				if(str[0]!='?'){
					if(str[0]==str[1]){
						cout << "-1\n";
						boo=false;
						break;
					}
				}
				else{
					if(str[1]=='a') str[0]='b';
					else str[0]='a';
				}
				continue;
			}
			if(i==str.size()-1){
				if(str[i]=='?'){
					if(str[i-1]=='a') str[i]='b';
					else str[i]='a';
				}
				continue;
			}
			if(str[i]!='?'){
				if(str[i]==str[i+1]||str[i]==str[i-1]){
					cout << "-1\n";
					boo=false;
					break;
				}
				continue;
			}
			if(str[i-1]!='a'&&str[i+1]!='a') str[i]='a';
			else if(str[i-1]!='b'&&str[i+1]!='b') str[i]='b';
			else str[i]='c';
		}
		if(boo) cout << str << "\n";
	}
	return 0;
}