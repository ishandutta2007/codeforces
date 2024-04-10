#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main(){
	int n,m;
	cin >> n >> m;
	int a[m+1];
	int b[m+1];
	for(int i=0;i<m;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	int res1=0;
	for(int p=1;p<=n;p++){
		int mmax=0;
		int chos=0;
		for(int i=0;i<m;i++){
			if(mmax<a[i]){
				chos=i;
				mmax=a[i];
			}
		}
		res1+=mmax;
		a[chos]--;
	}
	int res2=0;
	for(int p=1;p<=n;p++){
		int mmax=INF;
		int chos=0;
		for(int i=0;i<m;i++){
			if(mmax>b[i] and b[i]>0){
				chos=i;
				mmax=b[i];
			}
		}
		res2+=mmax;
		b[chos]--;
	}
	cout << res1 << " " << res2;
}