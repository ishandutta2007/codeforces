/*
    God save us everyone 
    will we burn inside the fires of a thousand suns?
    for the sins of our hands 
    the sins of our tongues
    the sins of our fathers
    the sins of our young..
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

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

int main(){
    int m , n;
    cin >> n >> m;
    if (n == 1){
	 cout << 1 << endl;
	 return  0;
    }
    if (m == 1){
	 cout << 2 << endl;
	 return  0;
    }
    if (m == n){
	 cout << n - 1 << endl;
	 return  0;
    }
    if (m - 1 >= n - m)  cout << m - 1 << endl;
    else    cout << m + 1 << endl;
    return 0;
}