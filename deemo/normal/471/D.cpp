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

typedef long long ll;
vector<int> vec , pat , s , str;
int n , w;
const int q = 1e9 + 20;
const int max_n = 5 * 1e5 + 100;
ll ans , z[max_n];

void get(){
    str.assign(pat.begin() , pat.end());
    str.push_back(q);
    for (int i = 0 ; i < s.size() ; i++)
	 str.push_back(s[i]);

    int L = 0 , R = 0;
    for (int i = 1 ; i < str.size() ; i++){
	 if (R < i){
	     L = R = i;
	     while (R < str.size() && str[R] == str[R - i])  R++;
	     R--;
	     z[i] = R - i + 1;
	 }
	 else{
	     if (z[i - L] < R - i)	 z[i] = z[i - L];
	     else{
		  L = i;
		  while (R < str.size() && str[R] == str[R - i])	 R++;
		  R--;
		  z[i] = R - i + 1;
	     }
	 }
    }

    for (int i = pat.size() + 1 ; i < str.size() ; i++)
	 if (z[i] == pat.size()) ans++;
}

int main(){
    cin >> n >> w;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 if (i != 0) s.push_back(vec[i] - vec[i - 1]);
    }
    vec.clear();
    for (int i = 0 ; i < w ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 if (i != 0) pat.push_back(vec[i] - vec[i - 1]);
    }
    if (w > n){
	 cout << 0 << endl;
	 return 0;
    }
    if (w == 1){
	 cout << n << endl;
	 return  0;
    }
    get();
    cout << ans << endl;
    return 0;
}