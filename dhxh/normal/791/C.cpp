#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

string str;

string name[105];

bool isr[105];

string na[105];
int nc = 0;

queue <int> q;
bool v[105];

int bl[105][105];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int init(){
	int i;
	char ch;
	for(i=1;i<=26;i++){
		ch = 'A' + i - 1;
		na[i].push_back(ch);
	}
	
	for(i=1;i<=26;i++){
		na[i + 26].push_back('A');
		ch = 'a' + i - 1;
		na[i + 26].push_back(ch);
	}
}

string getname(){
	nc++;
	
	return na[nc];
}

bool check(int j, int l){
	int i;
	for(i=j-k+1;i<=j+k-1;i++){
		if(bl[i][j] and name[i] == name[l]){
			return false;
		}
	}
	
	return true;
}

int main(){
	int i, j, l;
	int x, y;
	bool flag;
	
	cin >> n >> k;
	
	init();
	
	for(i=1;i<=n-k+1;i++){
		cin >> str;
		if(str == "YES"){
			isr[i] = true;
		}else{
			isr[i] = false;
		}
	}
	
	for(i=1;i<=n;i++){
		name[i] = getname();
		bl[i][i] = true;
	}
	
	for(i=1;i<=n-k+1;i++){
		if(isr[i]){
			for(j=i;j<=i+k-1;j++){
				for(l=i;l<=i+k-1;l++){
					bl[j][l] = true;
				}
			}
		}
	}
	
	for(i=1;i<=n-k+1;i++){
		if(!isr[i]){
			flag = false;
			for(j=i;j<=i+k-1;j++){
				for(l=i;l<=i+k-1;l++){
					if(!bl[j][l] and !v[j] and check(j, l)){	
						name[j] = name[l];
						v[l] = true;
						v[j] = true;
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		cout << name[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}