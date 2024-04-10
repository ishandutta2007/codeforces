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

int n , m , l , r , type , temp;
long long int c[100 * 1000 + 10];
long long int d[100 * 1000 + 10];
vector<int> vec;
vector<int> sec;

int main(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 if (i == 1) d[i] = temp;
	 else	  d[i] = d[i - 1] + temp;

	 sec.push_back(temp);
    }
    sort(sec.begin() , sec.end());
    for (int i = 1 ; i <= n ; i++){
	 if (i == 1) c[i] = sec[i - 1];
	 else	  c[i] = sec[i - 1] + c[i - 1];
    }

    cin >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> type >> l >> r;
	 if (type == 1)  cout << d[r] - d[l - 1] << endl;
	 else	  cout << c[r] - c[l - 1] << endl;
    }

    return 0;
}