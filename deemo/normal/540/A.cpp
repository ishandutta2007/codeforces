#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<iomanip>
#include<stack>
#include<cstdio>

using namespace std;

string s1 , s2;
int n;
long long int ans;

int main(){
    cin >> n;
    int temp;
    cin >> s1 >> s2;
    for(int i = 0 ; i < n ; i++){
	 temp = min(abs(int(s2[i]) - int(s1[i])) , 10 - (int(s1[i]) - 48) + (int(s2[i]) - 48));
	 temp = min(temp , 10 - (int(s2[i] - 48)) + (int(s1[i]) - 48));
	 ans += temp;
    }
    cout << ans << endl;
    return 0;
}