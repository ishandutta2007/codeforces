//And the clouds above move closer
//Looking so dissatisfied
//But the heartless wind kep blowing, blowing..

#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<cstdio>
#include<set>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const int max_n = 1e5 + 40;

int n;
set<int>	st;
vector<int>	vec;
int cnt[max_n];

int main(){
	scanf("%d", &n);
	for (int i= 1 ; i <= n ;i++)
		st.insert(i);
	vec.resize(n);
	for (int i=0 ; i < n;i ++){
		scanf("%d", &vec[i]);
		cnt[vec[i]]++;
		st.erase(vec[i]);
	}
	for (int i=0 ; i <n; i++){
		int t = vec[i];
		if (cnt[t] > 1 || t > n){
			cnt[t] -= 1;
			vec[i] = *st.begin();
			st.erase(st.begin());
		}	
	}	
	for (int i =0 ; i <n ;i++)
		printf("%d ", vec[i]);
	printf("\n");
	return	0;
}