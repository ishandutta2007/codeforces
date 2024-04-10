#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int t;

bool a[10005];
bool b[10005];

int main(){
	std::ios::sync_with_stdio(false);
	int i, j;
	int x;
	bool flag;
	
	cin >> n >> m;
	
	for(i=1;i<=m;i++){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		flag = false;
		cin >> t;
		for(j=1;j<=t;j++){
			cin >> x;
			if(x > 0){
				if(b[x]){
					flag =true;
				}
				a[x] = true;
			}else{
				x = -x;
				if(a[x]){
					flag = true;
				}
				b[x] = true;
			}
		}
		
		if(!flag){
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}