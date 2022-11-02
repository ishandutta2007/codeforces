#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 500009
using namespace std;
set<pair<int,int> >st1[5],st2[5];
int p[maxn];
int a[maxn], b[maxn];
void del(int x){
	//cout << x << endl;
	st1[a[x]].erase(make_pair(p[x], x));
	st2[b[x]].erase(make_pair(p[x], x));
	//cout << a[x] << " " << b[x] << endl;
	printf("%d ", p[x]);
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i =1; i <= n; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
		st1[x].insert(make_pair(p[i], i));
	}
	for(int i =1; i <= n; i++){
		int x;
		scanf("%d", &x);
		b[i] = x;
		st2[x].insert(make_pair(p[i], i));
	}
	int m;
	scanf("%d", &m);
	while(m--){
		int x;
		scanf("%d", &x);
		if(st1[x].size() == 0 && st2[x].size() == 0)
			printf("-1 ");
		else if(st1[x].size() == 0){
			auto it = st2[x].begin();
			int pos = it -> second;
			del(pos);
			//printf("%d ", p[pos]);
		}
		else if(st2[x].size() == 0){
			auto it = st1[x].begin();
			int pos = it -> second;
			del(pos);
			//printf("%d ", p[pos]);
		}
		else{
			auto it1 = st1[x].begin();
			auto it2 = st2[x].begin();
			int pos1 = it1 -> second;
			int pos2 = it2 -> second;
			if(p[pos1] < p[pos2])
				del(pos1);
			else
				del(pos2); 
 		}	
	}
	return 0;
}