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

int n , k , a , m;
vector<int> vec , sec;

bool ok(int ind){
    int cnt = 0;    
    sec.assign(vec.begin() , vec.begin() + (ind + 1));
    sort(sec.begin() , sec.end());
    cnt += (sec[0]) / (a + 1);
    for (int i = 0 ; i < ind ; i++)
	 cnt += (sec[i + 1] - sec[i]) / (a + 1);
    cnt += (n + 1 - sec[sec.size() - 1]) / (a + 1);
    return  cnt >= k; 
}

int main(){
    read_fast;
    cin >> n >> k >> a;
    cin >> m;
    int temp;
    for (int i = 0 ; i < m ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }

    int b = 0 , e = m - 1 , mid , ret = -1;
    while (b <= e){
	 mid = (b + e) / 2;
	 if (ok(mid))	   b = mid + 1;
	 else{
	     ret = mid;
	     e = mid - 1;
	 }
    }
    if (ret != -1)  ret++;
    cout << ret << endl;
    return 0;
}