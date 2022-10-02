#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

ULL a[MAXN];
int k[MAXN];
pair <int,ULL> t[MAXN];
int N;

int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> t[i].first >> t[i].second;
	sort(t,t+N);
	for(int i=0;i<N;i++)k[i]=t[i].first,a[i]=t[i].second;
	
	ULL act=0;
	for(int i=0;i<N;i++){
		if(i>0){
			for(int j=k[i-1]+1;j<=k[i] and act>1;j++){
				if(act%4==0)act/=4;
				else act=(act/4)+1;
			}
		}
		act=max(act,a[i]);
	}
	ULL p=1+k[N-1];
	while(act>4){
		p++;
		if(act%4==0)act/=4;
		else act=(act/4)+1;
	}
	cout << p << "\n";
}