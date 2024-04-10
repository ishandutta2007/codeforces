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

int mini , maxi , n;
vector<int> vec;
const int max_n = 2 * 1e6;
bool mark[max_n];
int mp[max_n];
int last[max_n] , first[max_n];
int l , r;

int main(){
    cin >> n;
    mini = n + 1;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 mp[temp] += 1;
	 if (mp[temp] > maxi)    maxi = mp[temp];
	 vec.push_back(temp);
    }
    for (int i = 0 ; i < n ; i++){
	 last[vec[i]] = i;
	 if (mark[vec[i]])	continue;
	 mark[vec[i]] = 1;
	 first[vec[i]] = i;
    }
    for (int i = 0 ; i < n ; i++){
	 if (mp[vec[i]] == maxi)
	     if (mini > last[vec[i]] - first[vec[i]] + 1){
		  mini = last[vec[i]] - first[vec[i]] + 1;
		  l = first[vec[i]];
		  r = last[vec[i]];
	     }
    }
    cout << l + 1 << " " << r + 1 << endl;
    return 0;
}