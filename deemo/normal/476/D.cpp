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

int n , k , ans;
const int maxi = 1e7;
bool mark[maxi];
const int max_n = 1e5 + 100;
vector<int> vec[max_n];
vector<int> sec;
//list<int>   sec;

int main(){
    cin >> k >> n;
    ans = (3 * k * 2 -1) * n;
    cout << ans << endl;
    int p = 1;
    for (int i = 0 ; i < k ; i++){
	 int t = p + 6;
	 for (; p < t ; p+=2){
	     vec[i].push_back(p * n);
	     if (p != 1) sec.push_back((p - 1) * n);
	 }
    }
    //cout << sec.size() << endl;//30000
    for (int i = 0 ; i < k ; i++){
	 int j = sec.size() - 1;
	 for ( ; j >= 0 ; j--)
	     if (__gcd(sec[j] , vec[i][0]) == n && __gcd(sec[j] , vec[i][1]) == n && __gcd(sec[j] , vec[i][2]) == n){
		  //if (mark[j] == 1)	 continue;
		  vec[i].push_back(sec[j]);
		  //mark[j] = 1;
		  break;
	     }
	 for (int z = sec.size() - 1 ; z >= j ; z--)
	     sec.pop_back();
	 for (j = 0 ; j < 4 ; j++){
	     if (j == 3) printf("%d\n",vec[i][j]);
	     else    printf("%d ",vec[i][j]);
	 }
    }
    return 0;
}