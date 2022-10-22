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

const int max_n = 2e6;
bool mark[max_n];

int main(){
    int n;
    cin >> n;
    char c;
    int temp;
    int t = 0 , ans = 0;
    deque<int>  saf;
    for (int i = 0 ; i < n ; i++){
	 cin >> c >> temp;
	 if (c == '+'){
	     mark[temp] = 1;
	     saf.pb(temp);
	 }
	 else{
	     saf.pb(-temp);
	     if (mark[temp] == 0)	 saf.push_front(temp);
	 }
    }
    for (int i = 0 ; i < saf.size() ; i++){
	 if (saf[i] > 0) t++;
	 else	  t--;
	 ans = max(ans , t);
    }
    cout << ans << endl;
    return 0;
}