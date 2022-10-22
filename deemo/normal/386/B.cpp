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

int n , k;
vector<int> vec;

int main(){
    cin >> n;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.pb(temp);
    }
    cin >> k;
    sort(vec.begin() , vec.end());
    int maxi = 0;
    for (int i = 0 ; i < n ; i++){
	 int cnt = 1;
	 for (int j = i + 1 ; j < n ; j++ , cnt++)
	     if (vec[j] - vec[i] > k)    break;
	 maxi = max(maxi , cnt);
    }
    cout << maxi << endl;
    return 0;
}