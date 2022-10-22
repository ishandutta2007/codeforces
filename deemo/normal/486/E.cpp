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
vector<int> vec(max_n) , ans;
int save[max_n] , dis[max_n] , cnt[max_n];
bool mark[max_n];

int main(){
    read_fast;
    cin >> n;
    for (int i = 0 ; i < n ; i++)	 cin >> vec[i];
    for (int i = 0 ; i < n ; i++){
	 int pos = lower_bound(ans.begin() , ans.end() , vec[i]) - ans.begin();
	 if (pos == ans.size())  ans.pb(vec[i]);
	 else	  ans[pos] = vec[i];
	 save[i] = pos + 1;
    }
    for (int i = n - 1 ; i >= 0 ; i--){
	 if (save[i] == ans.size()){
	     dis[save[i]] = max(dis[save[i]] , vec[i]);  
	     mark[i] = 1;
	 }
	 else if (dis[save[i] + 1] > vec[i]){
	     dis[save[i]] = max(dis[save[i]] , vec[i]);
	     mark[i] = 1;
	 }
	 if (mark[i])	   cnt[save[i]] += 1;
    }
    for (int i = 0 ; i < n ; i++){
	 if (!mark[i])   cout << 1;
	 else	  if (cnt[save[i]] == 1)   cout << 3;
	 else	  cout << 2;
    }
    cout << endl;
    return 0;
}