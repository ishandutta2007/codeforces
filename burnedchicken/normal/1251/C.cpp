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
	int t;
	cin >> t;
	string str,str1,str2;
	string::iterator it1,it2;
	loopi(noob,t){
		cin >> str;
		str1.clear();
		str2.clear();
		loop(str.size()){
			if(int(str[i]%2)==0) str1+=str[i];
			else str2+=str[i];
		}
		str.clear();
		if(str1.empty()){
			cout << str2 << "\n";
			continue;
		}
		if(str2.empty()){
			cout << str1 << "\n";
			continue;
		}
		it1=str1.begin();
		it2=str2.begin();
		while(1){
			if(*it1<*it2){
				str+=*it1;
				str1.erase(it1);
			}
			if(*it1>*it2){
				str+=*it2;
				str2.erase(it2);
			}
			if(it1==str1.end()){
				str+=str2;
				str2.clear();
				break;
			}
			if(it2==str2.end()){
				str+=str1;
				str1.clear();
				break;
			}
		}
		cout << str << "\n";
	}
	return 0;
}