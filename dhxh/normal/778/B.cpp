#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct ex {
	int n;
	int a;
	int b;
	int v[1005];
	int op;
};

ex op[5005];

map <string, int> s;

string ansa;
string ansb;

int n, m;

int tmpi;

int a[1005];

int sem(int j){
	int i;
	int x = 0;
	char ch;
	
	for(i=1;i<=n;i++){
		if(op[i].op == 1){
			op[i].n = op[i].v[j];
		}else if(op[i].op == 2){
			op[i].n = op[op[i].a].n ^ op[op[i].b].n;
		}else if(op[i].op == 3){
			op[i].n = op[op[i].a].n & op[op[i].b].n;
		}else if(op[i].op == 4){
			op[i].n = op[op[i].a].n | op[op[i].b].n;
		}
	}
	
	for(i=1;i<=n;i++){
		x += op[i].n;
	}
	
	return x;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int i, j;
	int x, y;
	char ch;
	int cnt;
	
	string str;
	string tmp;
	
	cin >> n >> m;
	
	s["?"] = 0;
	
	for(i=1;i<=n;i++){
		
		cin >> tmp;
		s[tmp] = i;
		cin >> tmp;
		
		cin >> tmp;
		
		if(tmp[0] == '0' or tmp[0] == '1'){
			op[i].op = 1;
			for(j=0;j<m;j++){
				op[i].v[j] = tmp[j] - '0';
			}
		}else{
			op[i].a = s[tmp];
			
			cin >> tmp;
			
			if(tmp == "XOR"){
				op[i].op = 2;
			}else if(tmp == "AND"){
				op[i].op = 3;
			}else{
				op[i].op = 4;
			}
			
			cin >> tmp;
			op[i].b = s[tmp];
		}
	}
	
	for(i=0;i<m;i++){
		
		op[0].n = 0;
		
		cnt = sem(i);
		
		a[i] = cnt;
	}
	
	for(i=0;i<m;i++){
	
		op[0].n = 1;
		
		cnt = sem(i);
		
		if(cnt > a[i]){
			ansa.push_back('1');
			ansb.push_back('0');
		}else if(cnt == a[i]){
			ansa.push_back('0');
			ansb.push_back('0');
		}else{
			ansa.push_back('0');
			ansb.push_back('1');
		}
	}
	
	cout << ansb << endl;
	cout << ansa << endl;
	
	return 0;
}