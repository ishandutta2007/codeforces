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

int main(){
    int a , b;
    cin >> a >> b;
    a = min(a , b);
    if (a % 2 == 1){
	 cout << "Akshat" << endl;
	 return  0;
    }
    cout << "Malvika" << endl;
    return 0;
}