#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;

#define P 1000000007
#define hash _____hash
typedef long long Int;

map<Int, int> hashes[108000];

string str[108000];
int n;
bool able[108000];
vector<int> ans;
int m;
int back[108000];

string rev(string str){
	string res = "";
	for(int i = str.size() - 1;i >= 0;i--){
		if('A' <= str[i] && str[i] <= 'Z')
			res += (char)(str[i] - 'A' + 'a');
		else
			res += str[i];
	}	
	return res;
}

Int hash(string str){
	Int res = 0;
	Int bb = 314159265;
	for(int i = 0;i < str.size();i++){
		res *= bb;
		res += (int)str[i];
		res %= P;
	}
	return res;
}
string sstr;


int main(){
	cin >> n;
	cin >> sstr;
	cin >> m;
	for(int i = 0;i < m;i++){
		cin >> str[i];
		hashes[str[i].size()][hash(rev(str[i]))] = i;
		
	}
	able[0] = true;
	for(int i = 0;i < n;i++){
		if(!able[i])continue;
		Int tmp = 0;
		Int bb = 314159265;
		for(int j = i;j < n;j++){
			tmp *= bb;
			tmp += (int)sstr[j];
			tmp %= P;
			if(hashes[j - i + 1].count(tmp) == 0)continue;
			back[j+1] = hashes[j - i + 1][tmp];
			able[j+1] = true;
		}
	}
	for(int i = n;i > 0;i -= str[back[i]].size()){
		ans.push_back(back[i]);
	}
	for(int i = ans.size() - 1;i >= 0;i--){
		if(i != ans.size() - 1)cout << " ";
		cout << str[ans[i]];
	}                                     cout << endl;
	return 0;
}