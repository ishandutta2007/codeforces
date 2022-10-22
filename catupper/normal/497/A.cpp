#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


bool ok(vector<string> x){
	vector<string> tmp = x;
	sort(tmp.begin(), tmp.end());
	return tmp == x;
}

int main(){
	vector<string> strs, tmp;
	string str[108];
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> str[i];
		strs.push_back("");
	}
	for(int i = 0;i < m;i++){
		vector<string> tmp = strs;
		for(int j = 0;j < n;j++){
			strs[j] += str[j][i];
		}
		if(ok(strs))continue;
		strs = tmp;
	}
	cout << m - strs[0].size() << endl;
	return 0;
}