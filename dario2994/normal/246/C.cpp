#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 54
using namespace std;

int a[MAXN];
int N,k;

int main(){
	cin >> N >> k;
	for(int i=0;i<N;i++)cin >> a[i];
	sort(a,a+N);
	for(int i=N;i>=0;i--){
		for(int j=0;j<i;j++){
			if(k==0)break;
			k--;
			cout << N-i+1 << " ";
			for(int k=N-1;k>=i;k--)cout << a[k] << " ";
			cout << a[j] << "\n"; 
		}
	}
}