/*#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,x; cin >> n>> x;
	vi arr(n);
	F0R(i,n) cin >> arr[i];
	sort(arr.begin(),arr.end());
	if (find(arr.begin(),arr.end(),x) == arr.end()) {
		int num2 = distance(ub(arr.begin(),arr.end(),x),arr.end());
		int num1 = n-num2;
		if (num1<num2) cout << (num2-num1);
		else cout << (num1-num2+1);
	} else {
		int num1 = distance(arr.begin(),find(arr.begin(),arr.end(),x));
		int num2 = n-1-num1;
		while (num1<arr.size()-1 && num1+1<num2 && arr[num1+1] == x) num1++, num2--;
		if (num1<num2) cout << (num2-num1-1);
		else cout << (num1-num2);
	}
}