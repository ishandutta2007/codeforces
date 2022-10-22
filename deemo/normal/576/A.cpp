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

const int max_n = 1e3 + 50;

int n;
vector<int>	ans;
bool ok[max_n];

bool pr(int x){	
	int cnt = 0;
	for (int i = 2 ; i <= x; i++){
		if (x % i != 0)	continue;
		if (ok[i])	cnt++;
	}
	return	cnt == 1;
}

bool check(int x){
	for (int i = 2 ; i * i <= x; i++)	
		if (x % i == 0)	return	false;
	return	true;
}

int main(){
	read_fast;
	cin >> n;
	for (int i = 2 ; i <= n ; i++)
		if (check(i))	ok[i] = 1;
	for (int i = 2 ; i <= n ; i++)
		if (pr(i))	ans.pb(i);	


	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
    return 0;
}