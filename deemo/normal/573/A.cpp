/*
    I found myself in Wonderland
    Get back on my feet again..
*/

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
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

const int max_n = 1e5 + 10;

int n;
vector<int> vec(max_n);

bool ok(int x){
    while (x % 2 == 0)  x /= 2;
    while (x % 3 == 0)  x /= 3;
    return  x == 1;
}

int main(){
    read_fast;
    cin >> n;
    for (int i = 0 ; i < n ; i++)	 cin >> vec[i];
    int g = __gcd(vec[0] , vec[1]);
    for (int i = 2 ; i < n ; i++)
	 g = __gcd(vec[i] , g);
    for (int i = 0 ; i < n ; i++){
	 if (!ok(vec[i] / g)){
	     cout << "NO" << endl;
	     return  0;
	 }
    }
    cout << "YES" << endl;
    return 0;
}