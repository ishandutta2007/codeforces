#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 300 + 5;

int n, x;
string t, last = "0";

void get(){
	for (int sz = (int)last.size(); ; sz++){
		int rem = x;
		t.resize(sz);
		if (sz == (int)last.size()){
			int ind = -1, ss = 0;
			for (int i = 0; i < sz; i++){
				ss += last[i] - '0';
				if (ss >= rem)	break;
				if (last[i] != '9')	ind = i;
			}
			if (ind == -1)	continue;
		
			t = last;
			t[ind]++;
			for (int i = 0; i <= ind; i++)	rem -= t[i] - '0';
			for (int i = sz - 1; i > ind; i--){
				t[i] = '0';
				int y = min(rem, 9);
				t[i] += y;
				rem -= y;
			}
			if (rem == 0)	return;
			for (int i = ind; i >= 0; i--){
				int y = min(rem, '9' - t[i]);
				t[i] += y;
				rem -= y;
			}
			if (rem == 0)	return;
		}
		else{
			t[0] = '1';
			rem--;
			for (int i = sz - 1; i >= 0; i--){
				if (i)
					t[i] = '0';
				int y = min(rem, '9' - t[i]);
				rem -= y;
				t[i] += y;
			}
			if (rem != 0)	continue;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	for (int i = 0; i < n; i++){
		cin >> x;
		get();
		cout << t << "\n";
		last = t;
	}
	return	0;	
}