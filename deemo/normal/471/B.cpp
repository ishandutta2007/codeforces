#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

vector<pair<int , int>> vec;
vector<int> vec2 , vec3;
int n , temp , fl;
int a[3000];
const int max_n = 3000;


bool help(pair<int , int>	a , pair<int , int> b){
    if (a.second < b.second)    return  true;
    if (a.second == b.second && a.first < b.first)  return  true;
    return  false;
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back({i , temp});
    }
    sort(vec.begin() , vec.end() , help);

    for (int i = 0 ; i < max_n ; i++)
	 a[i] = -1;
    
    for (int i = 0 ; i < n ; i++){
	 if (a[vec[i].second] != -1 && fl == 0){
	     fl = 1;
	     vec2.push_back(vec[i].first);
	     swap(vec2[vec2.size() - 1] , vec2[a[vec[i].second]]);
	     continue;
	 }
	 a[vec[i].second] = i;
	 vec2.push_back(vec[i].first);
    }
    if (fl == 0){
	 cout << "NO" << endl;
	 return  0;
    }
    fl = 0;
    for (int i = 0 ; i < max_n ; i++)
	 a[i] = -1;
    for (int i = 0 ; i < n ; i++){
	 if (a[vec[i].second] != -1 && fl < 2){
	     fl += 1;
	     vec3.push_back(vec[i].first);
	     if (fl == 1)	continue;
	     swap(vec3[vec3.size() - 1] , vec3[a[vec[i].second]]);
	     continue;
	 }
	 a[vec[i].second] = i;
	 vec3.push_back(vec[i].first);
    }
    if (fl != 2){
	 cout << "NO" << endl;
	 return  0;
    }
    cout << "YES" << endl;
    for (int i = 0 ; i < vec.size() ; i++){
	 if (i != vec.size() - 1)	 cout << vec[i].first + 1 << " ";
	 else	  cout << vec[i].first + 1 << endl;
    }
    for (int i = 0 ; i < vec2.size() ; i++){
	 if (i != vec2.size() - 1)	 cout << vec2[i] + 1 << " ";
	 else	  cout << vec2[i] + 1 << endl;
    }
    for (int i = 0 ; i < vec3.size() ; i++){
	 if (i != vec3.size() - 1)	 cout << vec3[i] + 1 << " ";
	 else	  cout << vec3[i] + 1 << endl;
    }
    return 0;
}