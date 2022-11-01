#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
int c[maxn];

vector <long long> vec;
vector <int> p;
vector <int> pb;
vector <int> cnt;

map <int, int> ms;

int s[5];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	return a[x] < a[y];
}

bool cmpb(int x, int y){
	if(cnt[x] != cnt[y])return cnt[x] < cnt[y];
	return vec[x] < vec[y];
}

int main(){
	int i, j;
	int ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	for(i=1;i<n;i++){
		if(!ms.count(a[c[i + 1]] - a[c[i]])){
			vec.push_back(a[c[i + 1]] - a[c[i]]);
			p.push_back(i);
			pb.push_back(0);
			cnt.push_back(1);
			ms[a[c[i + 1]] - a[c[i]]] = vec.size() - 1;
		}else{
			pb[ms[a[c[i + 1]] - a[c[i]]]] = i;
			cnt[ms[a[c[i + 1]] - a[c[i]]]]++;
		}
	}
	
	if(vec.size() == 1){
		printf("%d\n", c[1]);
	}else if(vec.size() == 2){
		s[0] = 0, s[1] = 1, s[2] = 2;
		sort(s, s + vec.size(), cmpb);
		if(cnt[s[0]] == 1){
			if(p[s[0]] == 1){
				printf("%d\n", c[1]);
			}else if(p[s[0]] == n - 1){
				printf("%d\n", c[n]);
			}else if(vec[s[0]] == 0){
				printf("%d\n", c[p[s[0]]]);
			}else{
				printf("-1\n");
			}
		}else if(cnt[s[0]] == 2 and vec[s[0]] * 2 == vec[s[1]] and pb[s[0]] == p[s[0]] + 1){
			printf("%d\n", c[pb[s[0]]]);
		}else{
			printf("-1\n");
		}
	}else if(vec.size() == 3){
		s[0] = 0, s[1] = 1, s[2] = 2;
		sort(s, s + vec.size(), cmpb);
		if(cnt[s[0]] == 1 and cnt[s[1]] == 1 and min(p[s[0]], p[s[1]]) + 1 == max(p[s[0]], p[s[1]]) and vec[s[0]] + vec[s[1]] == vec[s[2]]){
			printf("%d\n", c[max(p[s[0]], p[s[1]])]);
		}else{
			printf("-1\n");
		}
	}else{
		printf("-1\n");
	}
	
	
	return 0;
}