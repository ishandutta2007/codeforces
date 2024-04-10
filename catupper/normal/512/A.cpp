#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool come[108000];
vector<int> edge[108000];
vector<int> redge[108000];

string res;

void fail(){
	cout << "Impossible" << endl;
	exit(0);
}

int ind(int x){
	for(int i = 0;i < 26;i++){
		if(res[i] == x)return i;
	}
	exit(10);
}

void comp(string a, string b){
	int p = 0;
	while(p < a.size() && p < b.size() && a[p] == b[p])p++;
	if(p == b.size())fail();
	if(p == a.size())return;
	edge[a[p]].push_back(b[p]);
	redge[b[p]].push_back(a[p]);
}

void dfs(char x){
	if(come[x])return;
	come[x] =true;
	for(int i = 0;i < redge[x].size();i++){
		int to = redge[x][i];
		dfs(to);
	}
	res += x;
}

int main(){
	int n;
	string str[1080];
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> str[i];
		if(i){
			comp(str[i-1], str[i]);
		}
	}    
	for(int i = 'a';i <= 'z';i++){
		dfs(i);
	}          
	for(int i = 'a';i <= 'z';i++){
		for(int j = 0;j < edge[i].size();j++){
			if(ind(i) > ind(edge[i][j]))fail();
		}
	}
	cout << res << endl;
	return 0;
}