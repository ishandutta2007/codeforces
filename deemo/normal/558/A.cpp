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

bool operator <(pair<int , int> a , pair<int , int> b){
    if (a.first < b.first)	return	 true;
    return  false;
}

const ll max_n = 1e5;
ll par[max_n] , par2[max_n];
ll a , b , n , ans , s1 , s2;
vector<pair<int , int>> vec , sec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 if (a > 0)  vec.push_back({a , b}) , s1++;
	 else	  sec.push_back({a , b}) , s2++;
    }
    sort(vec.begin() , vec.end());
    sort(sec.begin() , sec.end());
    reverse(sec.begin() , sec.end());

    for (int i = 0 ; i < vec.size() ; i++)
	 par[i + 1] = par[i] + vec[i].second;
    for (int i = 0 ; i < sec.size() ; i++)
	 par2[i + 1] = par2[i] + sec[i].second;
    
    if (s1 <= s2){
	 ans = par[s1] + par2[min(s1 + 1 , s2)];
	 cout << ans << endl;
	 return  0;
    }
    else{
	 ans = par[s2 + 1] + par2[s2];
	 cout << ans << endl;
    }
    return 0;
}