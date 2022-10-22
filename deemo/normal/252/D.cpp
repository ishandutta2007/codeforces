#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

const int MAXN = 100 + 10;

int n, k;
int vec[MAXN], sec[MAXN], gec[MAXN], t[MAXN];

bool same(){
	for (int i = 0; i < n; i++)
		if (vec[i] != sec[i])	return	false;
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		vec[i]--;
	}
	for (int i = 0; i < n; i++){
		cin >> sec[i];
		sec[i]--;
	}
	copy(vec, vec + n, gec);
	iota(vec, vec + n, 0);
	if (same()){
		cout << "NO\n";
		return 0;
	}


	bool fl = 0, ok = 0;
	int ttt = -1;
	for (int i = 0; i < k; i++){
		{
			for (int j = 0; j < n; j++)
				t[j] = vec[gec[j]];
			bool zoo = 1;
			for (int j = 0; j < n; j++)
				if (t[j] != sec[j])	zoo = 0;
			if (!zoo)	ok = 1;

			zoo = 1;
			for (int j = 0; j < n; j++)
				t[gec[j]] = vec[j];
			for (int j = 0; j < n; j++)
				if (t[j] != sec[j])	zoo = 0;
			if (!zoo)	ok = 1;
		}
		
		
		for (int j = 0; j < n; j++)
			t[j] = vec[gec[j]];
		copy(t, t + n, vec);
		if (same()){
			ttt = i + 1;
			break;
		}

		
	}
	if (ttt != -1 && (ttt % 2 == k % 2))
		if (ttt == k || ok){
			cout << "YES\n";
			return 0;
		}

	fl = 1;
	ok = 0;
	iota(vec, vec + n, 0);
	ttt = -1;
	for (int i = 0; i < k; i++){
		{
			for (int j = 0; j < n; j++)
				t[j] = vec[gec[j]];
			bool zoo = 1;
			for (int j = 0; j < n; j++)
				if (t[j] != sec[j])	zoo = 0;
			if (!zoo)	ok = 1;

			zoo = 1;
			for (int j = 0; j < n; j++)
				t[gec[j]] = vec[j];
			for (int j = 0; j < n; j++)
				if (t[j] != sec[j])	zoo = 0;
			if (!zoo)	ok = 1;
		}
		
		for (int j = 0; j < n; j++)
			t[gec[j]] = vec[j];		
		copy(t, t + n, vec);
		if (same()){
			ttt = i + 1;
			break;
		}
	}

	if (ttt != -1 && (ttt % 2 == k % 2))
		if (ok){
			cout << "YES\n";
			return 0;
		}

	cout << "NO\n";
	
	return 0;
}