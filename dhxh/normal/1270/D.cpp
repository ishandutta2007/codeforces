#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;

int n, m, t, k;

vector <int> f;

bool vis[maxn];
int a[maxn];
pair <int, int> b[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

pair <int, int> query(vector <int> vec){
	cout << "?";
	for(auto x : vec){
		cout << " " << x;
	}
	cout << endl;
	int x, y;
	cin >> x >> y;
	return make_pair(x, y);
}

int main(){
	int i, j;
	vector <int> vec;
	
	cin >> n >> k;
	
	for(i=1;i<=k;i++){
		vec.push_back(i);
	}
	
	pair <int, int> p = query(vec);
	vector <int> A, B;
	
	if(k == 1){
		cout << "! 1" << endl;
		return 0;
	}
	
	for(i=1;i<=k;i++){
		if(i == p.first)continue;
		vec[i - 1] = k + 1;
		pair <int, int> tmp = query(vec);
		b[i] = tmp;
		vec[i - 1] = i;
		if(tmp == p){
			A.push_back(i);
			a[i] = 1;
		}else{
			B.push_back(i);
			a[i] = 2;
		}
	}
	
	if(B.size() == 0){
		vec[p.first - 1] = k + 1;
		pair <int, int> tmp = query(vec);
		if(tmp.second > p.second){
			cout << "! 1" << endl;
		}else{
			cout << "! " << k << endl;
		}
		return 0;
	}
	
	int x, y;
	
	for(i=1;i<=k;i++){
		if(a[i] == 2){
			x = i;
			break;
		}
	}
	
	pair <int, int> tmp = b[x];
	
	if(tmp.first == k + 1){
		if(tmp.second < p.second){
			cout << "! " << A.size() + 1 << endl;
		}else{
			cout << "! " << B.size() + 1 << endl;
		}
		return 0;
	}
	
	a[k + 1] = 1;
	vec[p.first - 1] = k + 1;
	tmp = query(vec);
	
	if(tmp.second < p.second){
		cout << "! " << A.size() + 1 << endl;
	}else{
		cout << "! " << B.size() + 1 << endl;
	}
	
	return 0;
}