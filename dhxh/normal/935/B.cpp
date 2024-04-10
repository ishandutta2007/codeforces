#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

char a[maxn];

vector <pair <int, int> > vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x = 0, y = 0;
	int ans = 0;
	
	cin >> n;
	cin >> a;
	
	vec.push_back(make_pair(x, y));
	
	for(i=0;i<n;i++){
		if(a[i] == 'U'){
			y++;
		}else{
			x++;
		}
		vec.push_back(make_pair(x, y));
	}
	
	for(i=1;i<vec.size()-1;i++){
		if(vec[i].first == vec[i].second){
			if(vec[i - 1].first > vec[i - 1].second and vec[i + 1].first < vec[i + 1].second){
				ans++;
			}
			if(vec[i - 1].first < vec[i - 1].second and vec[i + 1].first > vec[i + 1].second){
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}