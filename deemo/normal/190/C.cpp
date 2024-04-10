#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int cc, sz;
bool fail = 0;
string s[MAXN];
vector<string>	ans;

void get(){
	if (cc == sz){
		fail = 1;
		return;
	}

	if (s[cc] == "int"){
		ans.push_back(s[cc++]);
		return;
	}

	cc++;
	ans.push_back("pair<");
	get();
	ans.push_back(",");
	get();
	ans.push_back(">");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	string t;
	while (cin>>t)
		s[sz++] = t;
	
	get();
	if (fail || cc < sz){
		cout << "Error occurred\n";
		return	0;
	}
	for (auto v:ans)
		cout << v;
	cout << "\n";
	return	0;
}