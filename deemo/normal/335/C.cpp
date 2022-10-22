#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 100 + 5;

int save[MAXN][4];
bool mark[MAXN][4], mk[MAXN][4][MAXN], flag;
bool c[MAXN][3], d[MAXN][3];

int gr(int n, int type){
	if (n < 0)	return	type == 1 || type == 2;
	if (mark[n][type])
		return	save[n][type];
	
	mark[n][type] = 1;
	if (n == 0){
		if (type != 2 && type != 1)
			return	save[n][type] = 0;
		return	save[n][type] = 1;
	}
	if (n == 1){
		if (type == 0 || type == 3)	return	save[n][type] = 1;
		if (type == 1)	return	save[n][type] = 2;
		return	save[n][type] = 0;
	}

	if (type == 0)
		for (int i = 1; i <= n; i++)
			if (i != 1 && i != n)
				mk[n][type][gr(i - 2, 1) ^ gr(n - i - 1, 1)] = 1;
			else if (i == 1)
				mk[n][type][gr(n - i - 1, 1)] = 1;
			else mk[n][type][gr(i - 2, 1)] = 1;


	if (type == 1){
		for (int i = 1; i <= n; i++){
			if (i == 1)
				mk[n][type][gr(n - i - 1, 2)] = 1, mk[n][type][gr(n - i - 1, 3)] = 1;
			else if (i == n)
				mk[n][type][gr(n - 2, 1)] = 1, mk[n][type][gr(n - i - 2, 1) ^ 1] = 1;
			else
				mk[n][type][gr(i - 2, 1) ^ gr(n - i - 1, 2)] = 1,
					mk[n][type][gr(i - 2, 1) ^ gr(n - i - 1, 3)] = 1;
		}
		mk[n][type][gr(n - 1, 1)] = 1;
	}
	
	if (type == 2){
		for (int i = 1; i <= n; i++)
			if (i == 1)
				mk[n][type][gr(n - i - 1, 3)] = 1;
			else if (i == n)
				mk[n][type][gr(i - 2, 2) ^ 1] = 1;
			else
				mk[n][type][gr(i - 2, 1) ^ gr(n - i - 1, 3)] = 1;
		mk[n][type][gr(n - 1, 2)] = 1;
	}

	if (type == 3){
		for (int i = 1; i < n; i++){
			if (i == 1)
				mk[n][type][gr(n - i - 1, 2)] = 1, mk[n][type][gr(n - i - 1, 3) ^ 1] = 1;
			else 
				mk[n][type][gr(i - 2, 2) ^ gr(n - i - 1, 2)] = 1, 
					mk[n][type][gr(i - 2, 3) ^ gr(n - i - 1, 3)] = 1;
		}
		mk[n][type][gr(n - 1, 3)] = 1;
	}

	for (int i = 0; ; i++)
		if (!mk[n][type][i])	return	save[n][type] = i;
	return	0/0;
}

void init(){
	for (int i = 0; i < MAXN; i++)
		gr(i, 0), gr(i, 1), gr(i, 2), gr(i, 3);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();

	int n, k;
	cin >> n >> k;
	while (k--){
		int a, b;	cin >> a >> b;
		c[a][b] = 1;
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 2; j++){
			if (c[i][j])	d[i - 1][3 - j] = d[i][3 - j] = d[i + 1][3 - j] = 1;
			d[i][j] |= c[i][j];
		}

	int xx = 0;
	for (int i = 1; i <= n;){
		if (d[i][1] && d[i][2]){
			i++;
			continue;
		}
		int j = i;
		bool fl = 0;
		if (!(!d[i][1] & !d[i][2]))	j++, fl = 1;
		while (j <= n && !d[j][1] && !d[j][2])	j++;
	
		if (j == n + 1 || (d[j][1] && d[j][2])){
			if (fl)
				xx ^= gr(j - i - 1, 1);
			else
				xx ^= gr(j - i, 0);
		}
		else{
			if (!fl)
				xx ^= gr(j - i, 1);
			else{
				if (d[i][1] == d[j][1])
					xx ^= gr(j - i - 1, 3);
				else
					xx ^= gr(j - i - 1, 2);
			}
		}
		i = j + 1;
	}


	if (xx)
		cout << "WIN\n";
	else
		cout << "LOSE\n";
	return	0;
}