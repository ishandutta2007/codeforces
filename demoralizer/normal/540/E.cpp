#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

map<int, int> m;
vector<int> elems;
oset<int> s;

int getGreaterThanX(int x){
	return (int)s.size() - s.order_of_key(x);
}

int getElementsInRange(int l,int r){
	return upper_bound(elems.begin(), elems.end(),r) - lower_bound(elems.begin(), elems.end(),l);
}

int main(){
	int n;
	cin>>n;
	
	
	for(int i = 0; i < n ; i++){
		int a,b;
		cin>>a>>b;
		if(!m[a]) m[a] = a , elems.push_back(a);
		if(!m[b]) m[b] = b , elems.push_back(b);
		swap(m[a],m[b]);
	}
	
	sort(elems.begin(), elems.end());
	
	long long answer = 0;
	
	for(auto z:m){
		int a = z.first;
		int b = z.second;
		
		answer += getGreaterThanX(b);
		s.insert(b);
		
		int x = min(a,b);
		int y = max(a,b);
		
		answer += (y - x - 1) - getElementsInRange(x+1,y-1);
	}
	
	cout<<answer;
	
}