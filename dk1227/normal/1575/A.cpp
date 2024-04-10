#include <iostream>
#include <algorithm>

#define N 1000010
using namespace std;
int n, m;
struct node{
	int ind;
	string s;
}e[N];
bool cmp(node c, node d){
	string a = c.s, b = d.s;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == b[i]) continue;
		if(i % 2) return a[i] > b[i];
		else return a[i] < b[i];
	}
	return c.ind < d.ind;
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> e[i].s;
		e[i].ind = i;
	}
	sort(e, e + n, cmp);
	for(int i = 0 ; i < n ; i++)
	    cout << e[i].ind + 1 << ' ';
	return 0;
}