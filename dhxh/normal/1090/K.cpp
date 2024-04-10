#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n;

string a;
string b;

bool vis[30];

map <pair <string, string>, int> s;

vector <int> vec[maxn];
int ans = 0;

int main(){
	int i , j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a >> b;
		memset(vis, 0, sizeof(vis));
		for(j=0;j<b.length();j++){
			vis[b[j] - 'a'] = true;
		}
		
		while(a.size()){
			if(vis[a[a.size() - 1] - 'a']){
				a.pop_back();
			}else{
				break;
			}
		}
		
		b = "";
		
		for(j=0;j<=26;j++){
			char ch = 'a' + j;
			if(vis[j]){
				b.push_back(ch);
			}
		}
		
		if(s[make_pair(a, b)]){
			vec[s[make_pair(a, b)]].push_back(i);
		}else{
			s[make_pair(a, b)] = ++ans;
			vec[ans].push_back(i);
		}
	}
	
	cout << ans << endl;
	
	for(i=1;i<=ans;i++){
		cout << vec[i].size();
		for(auto j : vec[i]){
			cout << " " << j;
		}
		cout << endl;
	}
	
	return 0;
}