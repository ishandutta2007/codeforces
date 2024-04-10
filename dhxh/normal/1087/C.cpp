#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

struct ex {
	int x, y;
};

ex a[3];

vector <pair <int, int> > vec;

bool cmp(ex x, ex y){
	return x.x < y.x;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	for(i=0;i<3;i++){
		cin >> a[i].x >> a[i].y;
	}
	
	sort(a, a + 3, cmp);
	
	y = a[0].y;
	x = a[0].x;
	
	for(;x<=a[1].x;x++){
		vec.push_back(make_pair(x, y));
	}
	x--;
	if(a[0].y < a[1].y){
		y++;
		for(;y<=a[1].y;y++){
			vec.push_back(make_pair(x, y));
		}
		y--;
	}else if(a[0].y > a[1].y){
		y--;
		for(;y>=a[1].y;y--){
			vec.push_back(make_pair(x, y));
		}
		y++;
	}
	
	if(min(a[0].y, a[1].y) <= a[2].y and a[2].y <= max(a[0].y, a[1].y)){
		x++;
		for(;x<=a[2].x;x++){
			vec.push_back(make_pair(x, a[2].y));
		}
		x--;
	}else{
		if(min(a[0].y, a[1].y) > a[2].y){
			y = min(a[0].y, a[1].y) - 1;
			for(;y>=a[2].y;y--){
				vec.push_back(make_pair(x, y));
			}
			y++;
			x++;
			for(;x<=a[2].x;x++){
				vec.push_back(make_pair(x, y));
			}
			x--;
		}else if(max(a[0].y, a[1].y) < a[2].y){
			y = max(a[0].y, a[1].y) + 1;
			for(;y<=a[2].y;y++){
				vec.push_back(make_pair(x, y));
			}
			y--;
			
			x++;
			for(;x<=a[2].x;x++){
				vec.push_back(make_pair(x, y));
			}
			x--;
		}
	}
	
	cout << vec.size() << endl;
	
	for(i=0;i<vec.size();i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}
	
	return 0;
}