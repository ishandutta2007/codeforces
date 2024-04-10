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
const int max_n = 2 * 1e5 + 30;
vector<pair<int , int>> sec;
vector<int> ans;
int k , maxi;
int g[max_n] , b[max_n];

void init(){
    stack<int>  st , stt;
    for (int i = 1 ; i <= n ; i++){
	 while (!st.empty() && sec[st.top()] >= sec[i])	   st.pop();
	 if (st.empty()) g[i] = 0;
	 else	  g[i] = st.top();
	 st.push(i);
    }

    for (int i = n ; i >= 1 ; i--){
	 while (!stt.empty() && sec[stt.top()] >= sec[i])	   stt.pop();
	 if (stt.empty())	b[i] = n + 1;
	 else	  b[i] = stt.top();
	 stt.push(i);
    }
}

bool check(int m , int ln){
    int c = sec[m].second;
    return  (b[c] - g[c] - 1) >= ln;
}

bool help(pair<int , int>	a , pair<int , int> b){
    if (a.first < b.first)	return	 true;
    if (a.first > b.first)	return	 false;
    return  a.second < b.second;
}

int main(){
    cin >> n;
    sec.push_back({1 , 1});
    for (int i = 1 ; i <= n ; i++){
	 cin >> temp;
	 sec.push_back({temp , i});
    }
    init();
    sort(sec.begin() + 1 , sec.end() , help);
    k = n;
    
    for (int i = 1 ; i <= n ; i++){
	 while (check(k , i) != true)    k--;
	 ans.push_back(sec[k].first);
    }

    for (int i = 0 ; i < n ; i++){
	 if (i != n - 1) cout << ans[i] << " ";
	 else	  cout << ans[i] << endl;
    }

    return 0;
}