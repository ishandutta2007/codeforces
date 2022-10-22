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
#define Point pair<pair<int , int>, int>

const int max_n = 1e6 + 40;
const int SQRT = 1e3 + 5;

int n;
vector<Point>	vec;

bool help(Point a, Point b){
	if (a.first.first / SQRT != b.first.first / SQRT)
		return	a.first.first/SQRT < b.first.first/SQRT;
	return	a.first.second < b.first.second;
}

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &vec[i].first.first, &vec[i].first.second), vec[i].second = i + 1;
	sort(vec.begin(), vec.end(), help);
	for (int i = 0 ; i < n ;i++)
		printf("%d ", vec[i].second);
	printf("\n");
	return 0;
}