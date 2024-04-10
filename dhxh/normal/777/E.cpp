#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

struct ex {
	long long a;
	long long b;
	long long h;
};

struct stu {
	long long h[100005];
	long long a[100005];
	int p;
	
	long long topa(){
		return a[p];
	}
	
	long long toph(){
		return h[p];
	}
	
	int push(long long t, long long ht){
		p++;
		a[p] = t;
		h[p] = h[p - 1] + ht;
		return 0;
	}
	
	int pop(){
		p--;
		return 0;
	}
	
	stu(){p = 0;h[0] = 0;a[0] = 0;};
};

ex ring[100005];

stu s;

long long maxh = 0;

bool cmp(ex a, ex b){
	if(a.b != b.b){
		return a.b > b.b;
	}else{
		return a.a > b.a;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> ring[i].a;
		cin >> ring[i].b;
		cin >> ring[i].h;
	}
	
	sort(ring + 1, ring + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		while(ring[i].b <= s.topa()){
			s.pop();
		}
		s.push(ring[i].a, ring[i].h);
		maxh = max(maxh, s.toph());
	}
	
	cout << maxh << endl;
	
	return 0;
}