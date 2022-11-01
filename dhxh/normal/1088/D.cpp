#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int a, b, c, d;
	int op, opb;
	int f;
	
	a = 0;
	b = 0;
	
	cout << "? " << 0 << " " << 0 << endl;
	
	cin >> op;
	
	f = op;
	
	for(i=29;i>=0;i--){
		
		cout << "? "  << a + (1 << i) << " " << b + (1 << i) << endl;
		cin >> op;
		
		if(f == 0){
			cout << "? "  << a << " " << b + (1 << i) << endl;
			cin >> opb;
			if(opb == 1){
				a += (1 << i);
				b += (1 << i);
			}
			f = op;
		}else if(f + op == 0){
			if(f == 1){
				a += (1 << i);
			}else if(f == -1){
				b += (1 << i);
			}
			cout << "? "  << a << " " << b << endl;
			cin >> op;
			f = op;
		}else{
			if(f == 1){
				cout << "? "  << a << " " << b + (1 << i) << endl;
				cin >> opb;
				if(opb == 1){
					a += (1 << i);
					b += (1 << i);
				}
				f = op;
			}else{
				cout << "? "  << a + (1 << i) << " " << b << endl;
				cin >> opb;
				if(opb == -1){
					a += (1 << i);
					b += (1 << i);
				}
				f = op;
			}
		}
	}
	
	cout << "! " << a << " " << b << endl;
	
	return 0;
}