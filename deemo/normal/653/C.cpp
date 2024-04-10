#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;

int n, vec[MAXN], sm;

int f(int i){
	int ret = 0;
	if (i % 2 == 1){
		if (i && vec[i - 1] >= vec[i])	ret++;
		if (i < n - 1 && vec[i] <= vec[i + 1])	ret++;
	}
	else{
		if (i && vec[i - 1] <= vec[i])	ret++;
		if (i < n - 1 && vec[i] >= vec[i + 1])	ret++;
	}	
	return	ret;
}

bool check(int a, int b){
	if (a > b)	swap(a, b);
	if (a == b)	return	false;
	int g = 0;
	if (b - a == 1){
		if (a % 2 == 0 && vec[a] >= vec[b])	g++;
		if (a % 2 && vec[a] <= vec[b])	g++;
	}		
		
	int z = f(a) + f(b);
	swap(vec[a], vec[b]);
	int y = f(a) + f(b);
	int gg = 0;
	if (b - a == 1){
		if (a % 2 == 0 && vec[a] >= vec[b])	gg++;
		if (a % 2 && vec[a] <= vec[b])	gg++;
	}	

	swap(vec[a], vec[b]);
	return sm - (z - g) + (y - gg) == 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> vec[i];
	int ind = -1;
	for (int i = 0; i < n - 1; i++){
		if (i % 2 == 0 && vec[i] >= vec[i + 1]){
			sm++;
			if (ind == -1)	ind = i;
		}
		if (i % 2 && vec[i] <= vec[i + 1]){
			sm++;
			if (ind == -1)	ind = i;
		}
	}

	int cn = check(ind, ind + 1);
	for (int j = 0; j < n; j++){
		if (j != ind+1)	
			cn += check(ind, j);
		if (j != ind)
			cn += check(ind + 1, j);
	}
			
	cout << cn << "\n";
	return	0;	
}