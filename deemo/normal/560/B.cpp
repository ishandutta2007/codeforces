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
#include<fstream>
#include<list>
#include<sstream> 

using namespace std;

typedef long long ll;
#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define push_back pb
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

int main(){
    int a1 , a2 , a3 , b1 , b2 , b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    bool flag = 0;
    if (a2 <= a1 && b2 <= b1 && a1 - a2 >= a3 && b1 >= b3)  flag = 1;
    if (a2 <= a1 && b2 <= b1 && a1 - a2 >= b3 && b1 >= a3)  flag = 1;
    if (a2 <= a1 && b2 <= b1 && a3 <= a1 && b3 <= b1 - b2)  flag = 1;
    if (a2 <= a1 && b2 <= b1 && b3 <= a1 && a3 <= b1 - b2)  flag = 1;
    if (a1 >= b2 && b1 >= a2 && a1 - b2 >= a3 && b1 >= b3)  flag = 1;
    if (a1 >= b2 && b1 >= a2 && a1 - b2 >= b3 && b1 >= a3)  flag = 1;
    if (a1 >= b2 && b1 >= a2 && a1 >= a3 && b1 - a2 >= b3)  flag = 1;
    if (a1 >= b2 && b1 >= a2 && a1 >= b3 && b1 - a2 >= a3)  flag = 1;
    if (flag)   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}