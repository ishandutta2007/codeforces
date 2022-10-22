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

string s;
int ans;

int main(){
    cin >> s;
    ans = (s.size() + 1) * 26;
    ans -= s.size();
    cout << ans << endl;
    return 0;
}