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

int n , temp , maxi;
int d[1000 * 100 + 30];
vector<int> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    if (n == 1 || n == 2){
	 cout << n << endl;
	 return 0;
    }

    d[0] = d[1] = 1;
    for (int i = 2 ; i < vec.size() ; i++)
	 if (vec[i] == vec[i - 1] + vec[i - 2])  d[i] = 1;

    int maxi = 0;
    int i = 2;
    while (i < vec.size()){
	 temp = 0;
	 while (i < vec.size() && d[i] == 1){
	     i++;
	     temp++;
	 }
	 maxi = max(temp + 2 , maxi);
	 i++;
    }    
    cout << maxi << endl;

    return 0;
}