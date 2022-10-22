#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct trie{
	 trie *child[26];
	 trie(){
	 	fill(child, child + 26, (trie*)0);
	 }
};

trie start;
int n, k;
string str;

int dp(trie *now, int turn){
	for(int i = 0;i < 26;i++){
		if(now->child[i] == 0)continue;
		if(dp(now->child[i], 1 - turn) == turn)return turn;
	}
	return 1 - turn;
}

int lose(trie *now, int turn){
	int cnt = 0;
	for(int i = 0;i < 26;i++){
		if(now->child[i] == 0)continue;
		cnt++;
		if(lose(now->child[i], 1 - turn) == turn)return turn;
	}
	if(cnt == 0)return turn;
	else return 1 - turn;
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> str;
		trie *now = &start;
		for(int j = 0;j < str.size();j++){
			char c = str[j];
			c -= 'a';
			if(now->child[c] == 0){
				now->child[c] = new trie();
			}
			now = now->child[c];
		}
	}
	int result = dp(&start, 0);
	int l = lose(&start, 0);
	if(result == 0 && l == 0){
		cout << "First" << endl;
		return 0;
	}
	if(result == 0 && l == 1){
		if(k % 2 == 0)cout << "Second" << endl;
		else cout << "First" << endl;
		return 0;
	}
	if(result == 1 && l == 0){
		cout << "Second" << endl;
		return 0;
	}
	cout << "Second" << endl;
	return 0;
}