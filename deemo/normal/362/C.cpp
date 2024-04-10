#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 5e3 + 40;

int n;
int vec[MAXN];
int fen[MAXN];

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(int v){
	for (v++; v < MAXN; v += v & (-v))
		fen[v]++;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i], vec[i]++;

	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (vec[j] < vec[i])	c++;

	int maxi = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		memset(fen, 0, sizeof(fen));
		for (int j = i + 1; j < n; j++){
			int temp = bool(vec[j] < vec[i]);
			temp += get(vec[i]);
			temp -= (j - i - 1) - get(vec[i]);
			temp += (j - i - 1) - get(vec[j]);
			temp -= get(vec[j]);
			if (temp == maxi)
				cnt++;
			else if (temp > maxi){
				maxi = temp;
				cnt = 1;
			}
			add(vec[j]);
		}
	}
	cout << c - maxi << " " << cnt << endl;
	return 0;	
}