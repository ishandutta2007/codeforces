#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef pair<int, int> P;

set<int> s;
int n, l, x, y;
int a[108000];
int main(){
	cin >> n >> l >> x >> y;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	int xyn;
	bool bxy = false, bx = false, by = false;
	for(int i = 0;i < n;i++){
		if(s.count(a[i] + x + y) || a[i] + x <= l && s.count(a[i] + x - y)){
			bxy = true;
			xyn = a[i] + x;
		}
		if(a[i] - x >= 0 && s.count(a[i] - x + y)){
			bxy = true;
			xyn = a[i] - x;
		}
		
		if(s.count(a[i] + x))bx = true;
		if(s.count(a[i] + y))by = true;
	}
	if(bx && by){
		cout << 0 << endl;
		return 0;
	}
	if(bx && !by){
		cout << 1 << endl;
		cout << y << endl;
	}
	if(!bx && by){
		cout << 1 << endl;
		cout << x << endl;
	}
	if(!bx && !by && bxy){
		cout << 1 << endl;
		cout << xyn<< endl;
	}
	if(!bx && !by && !bxy){
		cout << 2 << endl;
		cout << x << " " << y << endl;
	}
	return 0;
}