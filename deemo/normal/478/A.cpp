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

int sum;

int main(){
    for (int i = 0 ; i < 5 ; i++){
	 int temp;
	 cin >> temp;
	 sum += temp;
    }
    if (sum % 5 == 0 && sum != 0)  cout << sum / 5 << endl;
    else    cout << -1 << endl;
    return 0;
}