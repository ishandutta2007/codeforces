#include <bits/stdc++.h>
#define double long double
using namespace std;
vector<string> v;
struct Vertex{int go[26]; bool can; int how;};
vector<Vertex> bor;
int var;
bool ploh, govno;
void create(){
	Vertex nv;
	for (int i=0; i < 26; i++) nv.go[i] = -1;
	nv.can = false;
	nv.how = 0;
	bor.push_back(nv);
}
int add(int vertex, int wh){
	if (bor[vertex].how <= 1 && !ploh && vertex) var++;
	if (bor[vertex].go[wh]==-1){
		if (!bor[vertex].can &&!ploh) govno = true;
		ploh = true;
		create();
		bor[vertex].go[wh] = bor.size()-1;
	}
	return bor[vertex].go[wh];
}
int down(int vertex, int wh){
	bor[vertex].how++;
	return bor[vertex].go[wh];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//freopen("1.txt", "r", stdin);
	string s;
    string bad = ",.?!-'";
    int ans = 0;
    while (getline(cin,s)){
		ans++;
		string now = "";
		for (int i=0; i < s.size(); i++){
			bool can = false;
			for (int j=0; j < bad.size(); j++){
				if (bad[j] == s[i]) can = true;
			}
			if (can || int (s[i]) == 32){
				ans++;
				if (now != "") v.push_back(now);
				now = "";
			}
			else{
				now+=s[i];
			}
		}
		if (now.size() != 0) v.push_back(now);
    }
    create();
    for (int i=0; i < v.size(); i++){
		ans += v[i].size();
		int now = 0;
		var = -2, ploh = false;
		//cout << i << endl;
		govno = false;
		for (int j=0; j < v[i].size(); j++){
			now = add(now, v[i][j] - 'a');
		}
		//cout << var << endl;
		if (bor[now].can) var++;
		if ((ploh || bor[now].can) && !govno) ans -= max((int) 0, var);
		//cout << v[i] << " " << ans << endl;
		if (bor[now].can) continue;
		bor[now].how++;
		bor[now].can = true;
		now = 0;
		for (int j=0; j < v[i].size(); j++){
			now = down(now, v[i][j] - 'a');
		}
    }
    cout << ans << endl;
}