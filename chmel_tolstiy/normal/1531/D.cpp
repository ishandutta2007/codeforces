#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int kk = 300;

void process(int ti, const vector<int>& commands, vector<bool>& locked0, vector<bool>& locked1, vector<int>& color0, vector<int>& color1) {
	bool lk = false;
	int color = -1;
	for (int i = ti * kk; i < (ti + 1) * kk and i < commands.size(); ++i) {
		if (commands[i] == -1) lk = true;
		else {
			if (commands[i] == -2) 
				lk = false;
			else 
				if (!lk) color = commands[i];
		}
	}
	locked0[ti] = lk;
	color0[ti] = color;
	lk = true;
	color = -1;
	for (int i = ti * kk; i < (ti + 1) * kk and i < commands.size(); ++i) {
		if (commands[i] == -1) lk = true;
		else {
			if (commands[i] == -2) 
				lk = false;
			else 
				if (!lk) color = commands[i];
		}
	}
	locked1[ti] = lk;
	color1[ti] = color;

	//cerr << locked0[ti] << ' ' << locked1[ti] << ' ' << color0[ti] << ' ' << color1[ti] << endl;
}

int answer(const vector<bool>& locked0, const vector<bool>& locked1, const vector<int>& color0, const vector<int>& color1) {
	bool lk = false;
	int color = 0;
	for (int i = 0; i < locked0.size(); ++i) {
		if (lk) {
			lk = locked1[i];
			if (color1[i] != -1)
				color = color1[i];
		} else {
			lk = locked0[i];
			if (color0[i] != -1)
				color = color0[i];			
		}
	}
	return color;
}

void solve() {

	map<string, int> c2i;
	c2i["blue"] = 0;
	c2i["red"] = 1;
	c2i["orange"] = 2;
	c2i["yellow"] = 3;
	c2i["green"] = 4;
	c2i["indigo"] = 5;
	c2i["violet"] = 6;
	c2i["lock"] = -1;
	c2i["unlock"] = -2;

	vector<string> i2c = {"blue","red","orange","yellow","green","indigo","violet"};

	string op;
	int n;
	cin >> n;
	vector<int> commands(n);
	for (int i = 0; i < n; ++i) {
		cin >> op;
		commands[i] = c2i[op];
	}

	int tt = (n + kk - 1) / kk;

	vector<bool> locked0(tt), locked1(tt);
	vector<int> color0(tt), color1(tt);

	for (int ti = 0; ti < tt; ++ti) {
		process(ti, commands, locked0, locked1, color0, color1);
	}

	cout << i2c[answer(locked0, locked1, color0, color1)] << '\n';

	int q; cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int pos; cin >> pos; --pos;
		cin >> op;
		commands[pos] = c2i[op];
		int ti = pos / kk;
		process(ti, commands, locked0, locked1, color0, color1);
		cout << i2c[answer(locked0, locked1, color0, color1)] << '\n';
	}
}

int main() {
	cin.sync_with_stdio(false);
	solve();
	return 0;
}