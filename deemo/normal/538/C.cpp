#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<cstdio>
#include<iomanip>

using namespace std;

int n , m , ha , hb , maxi;
vector<pair<int , int>> vec;

int main(){
    int maxi = -1;
    cin >> n >> m;
    int a , b;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b;
	 if (i == 0)
	     if (a != 1) vec.push_back({1 , b + a - 1});

	 vec.push_back({a , b});
    } 
    if (a != n) vec.push_back({n , b + (n - a)});
    maxi = vec[0].second;

    for (int i = 0 ; i < vec.size() - 1 ; i++){
	 a = vec[i].first;
	 b = vec[i + 1].first;
	 ha = vec[i].second;
	 hb = vec[i + 1].second;
	 int k = b - a;

	 if (k < abs(ha - hb)){
	     cout << "IMPOSSIBLE" << endl;
	     return 0;
	 }

	 if (ha >= hb){
	     int z = k - abs(ha - hb);
	     int temp = ha + floor(z / 2);
	     if (maxi == -1 || temp > maxi)  maxi = temp;
	     continue;
	 }
	 if (ha < hb){
	     int z = k - abs(ha - hb);
	     int temp = hb + floor(z / 2);
	     if (maxi == -1 || temp > maxi)  maxi = temp;
	     continue;
	 }
    }
    cout << maxi << endl;

    return 0;
}