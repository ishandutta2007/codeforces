typedef unsigned long long ULL;
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAXN 100010
using namespace std;

int N;
ULL K;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i=0;i<N;i++)cin >> a[i];
	sort(a,a+N);
	ULL S=0;
	queue <int> dentro;
	int res=0;
	int chi=-1;
	int i=0;
	while(i<N){
		int act=a[i];
		int j=i;
		while(j<N and act==a[j])j++;
		if(i>0)S+=ULL(dentro.size())*ULL(a[i]-a[i-1]);
		for(int h=i;h<j;h++)dentro.push(act);
		while(S>K){
			S-=act-dentro.front();
			dentro.pop();
		}
		if(int(dentro.size())>res){
			res=dentro.size();
			chi=act;
		}
		i=j;
	}
	cout << res << " " << chi;
}