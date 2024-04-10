#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<map>
#include<ctime>
#include<cstdlib>

using namespace std;

typedef long long ll;

const int MAXN = 4 + 1;

int n, m, sum, vec[MAXN * MAXN];
int d[MAXN][MAXN], sec[MAXN * MAXN], sc[MAXN * MAXN];
int mark[MAXN * MAXN];
bool fl;
vector<int>	gec, fr;
map<int, int>	cnt;

void gen(int ind){
	if (ind == m){
		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++, c++)
				d[i][j] = sec[c];

		if (n == 1)	fl = 1;
		if (fl)	return;
		if ((d[0][0] + d[0][1] + d[0][2]) * n == sum && (d[1][0] + d[1][1] + d[1][2]) * n == sum)
			if ((d[0][0] + d[1][0] + d[2][0]) * n == sum && (d[0][1] + d[1][1] + d[2][1]) * n == sum)
				if ((d[0][0] + d[1][1] + d[2][2]) * n == sum){
					int z = 0;
					for (int i = n - 1; i >= 0; i--)
						z += d[i][(n - 1) - i];
					if (z * n == sum)	fl = 1;
				}
		return;
	}

	for (int i = 0; i < m; i++){
		if (mark[i])	continue;
		mark[i] = 1;
		sec[ind] = vec[i];
		gen(ind + 1);
		mark[i] = 0;
		if (fl)	return;
	}
}

void gg(int ind){
	if (ind == 4 && (sec[0] + sec[1] + sec[2] + sec[3]) * 4 != sum)	return;
	if (ind == 8 && (sec[4] + sec[5] + sec[6] + sec[7]) * 4 != sum)	return;
	if (ind == 12 && (sec[8] + sec[9] + sec[10] + sec[11]) * 4 != sum)	return;
	if (ind == 16 && (sec[12] + sec[13] + sec[14] + sec[15]) * 4 != sum)	return;
	if (ind == 13 && (sec[0] + sec[4] + sec[8] + sec[12]) * 4 != sum)	return;
	if (ind == 14 && (sec[1] + sec[5] + sec[9] + sec[13]) * 4 != sum)	return;
	if (ind == 15 && (sec[2] + sec[6] + sec[10] + sec[14]) * 4 != sum)	return;
	if (ind == 16 && (sec[3] + sec[7] + sec[11] + sec[15]) * 4 != sum)	return;
	if (ind == 13 && (sec[3] + sec[6] + sec[9] + sec[12]) * 4 != sum)	return;
	if (ind == 16){
		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++, c++)
				d[i][j] = sec[c];

		if ((d[0][0] + d[1][1] + d[2][2] + d[3][3]) * 4 != sum)	return;
		fl = 1;
		return;
	}

	for (int i = 0; i < m; i++)
		if (mark[i] == 0){
			mark[i]++;
			sec[ind] = vec[i];
			gg(ind + 1);
			mark[i]--;
			if (fl)	return;
		}
	
}

int main(){
	srand(time(0));
	cin >> n;	m = n * n;
	for (int i = 0; i < m; i++)	cin >> vec[i], sum += vec[i];
	if (n < 4){
		gen(0);	
		assert(fl);
		cout << d[0][0] + d[0][1] + d[0][2] << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cout << d[i][j] << " ";
			cout << endl;
		}
		return	0;
	}
	//there's only one case remaining -> n == 4
	//9 diffrent elements (or maybe enough for the third task?)
	random_shuffle(vec, vec + m);
	gg(0);
	cout << d[0][0] + d[0][1] + d[0][2] + d[0][3] << endl;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	/* not now!
	for (int i = 0; i < (1 << 16); i++){
		if (i < (1 << 8) && __builtin_popcount(i) == 4)	fr.push_back(i);
		int z = 0;
		for (int j = 0; j < 16; j++)
			if ((i >> j) & 1)	z += vec[j];
		if (__builtin_popcount(i) == 8 && z * 2 == sum)	gec.push_back(i);
	}
	cout << fr.size() << " " << gec.size() << endl;*/
	return	0;
}