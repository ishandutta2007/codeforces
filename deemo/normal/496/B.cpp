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

string s[20];
int n;
vector<string>  vec;

int main(){
    cin >> n;
    cin >> s[0];
    vec.push_back(s[0]);
    for (int i = 1 ; i < 10 ; i++){
	 for (int j = 0 ; j < s[0].size() ; j++){
	     if (s[i - 1][j] != '9')	 s[i] += char(s[i - 1][j] + 1);
	     else    s[i] += '0';
	 }
	 vec.push_back(s[i]);
    }

    for (int i = 0 ; i < 10 ; i++)
	 for (int p = 1 ; p < n ; p++){
	     string ret = "";
	     for (int j = p ; j < n ; j++)
		  ret += vec[i][j];
	     for (int j = 0 ; j < p ; j++)
		  ret += vec[i][j];
	     vec.push_back(ret);
	 }
    sort(vec.begin() , vec.end());
    cout << vec[0] << endl;

    return 0;
}