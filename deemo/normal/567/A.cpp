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

const int max_n = 3e5;
int b[max_n] , a[max_n];

int main(){
    read_fast;
    int n;
    vector<pair<int , int>>  vec;
    cin >> n;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.pb({temp , i});
    } 
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < vec.size() ; i++){
	 int maxi = abs(vec[0].first - vec[i].first);
	 maxi = max(maxi , abs(vec[vec.size() - 1].first - vec[i].first));
	 a[vec[i].second] = maxi;
	 if (i == 0) maxi = vec[1].first - vec[0].first;
	 else	  if (i == n - 1) maxi = vec[i].first - vec[i - 1].first;
	 else	  maxi = min(int(vec[i].first - vec[i - 1].first) , int(vec[i + 1].first - vec[i].first));
	 b[vec[i].second] = maxi; 
    }
    for (int i = 0 ; i < n ; i++)
	 cout << b[i] << " " << a[i] << endl;

    return 0;
}