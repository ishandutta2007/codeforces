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

int k;
string s;
vector<string>  ans;
bool mark[400];
set<char>   st;

int main(){
    cin >> k;
    cin >> s;
    for (int i = 0 ; i < s.size() ; i++)
	 st.insert(s[i]);
    if (st.size() < k){
	 cout << "NO" << endl;
	 return  0;
    }
    cout << "YES" << endl;
    for (int i = 0 ; i < s.size() ;){
	 string temp = "";
	 temp += s[i];
	 mark[s[i]] = 1;
	 i++;
	 while (i < s.size() && (mark[s[i]] == 1 || k == 1)){
	     temp += s[i];
	     i++;
	 }
	 k--;
	 ans.push_back(temp);
    }
    for (int i = 0 ; i < ans.size() ; i++)
	 cout << ans[i] << endl;
    return 0;
}