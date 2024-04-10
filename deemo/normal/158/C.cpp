#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int q;
map<string, string>	par;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	string cur = "/";
	while (q--){
		string t;	cin >> t;
		if (t == "pwd"){
			cout << cur << "\n";
			continue;
		}	
		cin >> t;
		int i = 0;
		if (t[0] == '/'){
			cur = "/";
			i++;
		}
		string temp = "";
		for (int j = i; j < t.size();){
			temp = "";
			while (j < t.size() && t[j] != '/'){
				temp += t[j];
				j++;
			}	
			if (temp == "..")
				cur = par[cur];
			else{
				string g = cur;
				cur += temp + "/";
				par[cur] = g;
			}
			j++;
		}
	}
	return 0;
}