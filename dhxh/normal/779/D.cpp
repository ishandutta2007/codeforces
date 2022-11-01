#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string stra;
string strb;
string str;

int se[200005];
bool v[200005];

int n, m;



int getstr(int x){
	int i, j;
	memset(v, 0, sizeof(v));
	
	for(i=1;i<=x;i++){
		v[se[i]] = true;
	}
	
	str = "";
	
	for(i=1;i<=n;i++){
		if(!v[i]){
			str.push_back(stra[i - 1]);
		}
	}
	
	return 0;
}

bool check(){
	int i, j;
	int l = str.length();
	j = 0;
	
	for(i=0;i<l;i++){
		if(str[i] == strb[j]){
			j++;
			if(j == m){
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int i, j;
	int x;
	
	int l, r, mid;
	
	cin >> stra;
	cin >> strb;
	
	n = stra.length();
	m = strb.length();
	
	for(i=1;i<=n;i++){
		cin >> se[i];
	}
	
	l = 1;
	r = n - m;
	
	while(l < r){
		mid = (l + r) / 2;
		getstr(mid);
		if(check()){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	getstr(l);
	if(!check()){
		l--;
	}
	
	cout << l << endl;
	
	return 0;
}