//Toxic

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9 + 4 + 1e6;
const int MAXN = 3e5 + 20;

int n, k, vec[MAXN];
bool fail;
vector<int>	sec;
set<int>	st;

void process(int ind){
	st.clear();
	for (int i = 1; i < sec.size(); i++)
		if (sec[i] <= sec[i - 1]){
			fail = 1;
			return;
		}

	int l = 0, r = 0;
	for (int i = ind; i < n || r - l; i += k){
		if (i >= n)	vec[i] = INF + 1;
		if (vec[i] != INF){
			if (r - l){
				if (l == 0){
					int sz = r - l;
					sz/=2;
					int ss = min(vec[i] - 1, sz);
					for (int j = i - k; j >= 0; j -= k)
						vec[j] = ss--;
				}
				else{
					int sz = r - l, ss;
					if (vec[i] - vec[i - (sz + 1) * k] - 1 < sz)	{fail = 1; return;}
					int tmp = sz;
					sz/=2;
					if (vec[i - (tmp + 1) * k] >= 0)	ss = vec[i - (tmp + 1) * k] + 1;
					else	ss = min(max(-sz, vec[i - (tmp + 1) * k] + 1), vec[i] - tmp);
	
					for (int j = i - tmp * k; j < i; j += k)
						vec[j] = ss++;
				}
			}
			r = l = i/k + 2;
			continue;
		}
		r++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;	
	for (int i = 0; i < n; i++){
		string temp;	bool f = 0;	cin >> temp;	if (temp[0] == '-')	temp.erase(temp.begin()), f = 1;
				if (temp == "?")	vec[i] = INF;	else	for (int j = 0; j < temp.size(); j++)	vec[i] = (vec[i] * 10 + (temp[j] - '0'));	if (f)	vec[i] *= -1;}

	for (int i = 0; i < k; i++){
		sec.clear();
		for (int j = i; j < n; j += k)
			if (vec[j] != INF)	
				sec.push_back(vec[j]);
		process(i);
	}

	if (fail){
		cout << "Incorrect sequence" << endl;
		return	0;
	}

	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
	return	0;
}