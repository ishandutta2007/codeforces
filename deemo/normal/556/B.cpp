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

int n , temp;
vector<int> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    while (vec[0] != 0){
	 for (int i = 0 ; i < n ; i++){
	     if (i % 2 == 0)	vec[i] = (vec[i] + 1) % n;
	     else    vec[i] = (vec[i] + n - 1) % n;
	 }
    }
    int flag = 0;
    for (int i = 0 ; i < n ; i++)
	 if (vec[i] != i)	flag = 1;
    if (flag == 0){
	 cout << "YES" << endl;
	 return  0;
    } 
    cout << "NO" << endl;
    return 0;
}