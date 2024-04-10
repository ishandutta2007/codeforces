#include <bits/stdc++.h>
 
using namespace std; 	
typedef long long ll;
const int N = 2e6+50;
const int oo = 1e9;
 
int a[1001];
bool nprime[N];
int main(){
	for(int i=2;i<=N;i++){
		if(nprime[i])continue;
		for(int j=i+i;j<N;j+=i)nprime[j]=1;
	}
	int n,o=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)o++;
	}
	if(o){
		for(int i=0;i<n;i++){
			if(a[i]==1)continue;
			if(!nprime[a[i]+1]){
				cout << o+1 << endl;
				for(int j=0;j<o;j++){
					cout << 1 << ' ';
				}
				cout << a[i];
				return 0;
			}
		}
	}
	if(o>=2){
		cout << o << endl;
		for(int i=0;i<o;i++){
			cout << 1 << ' ';
		}
		return 0;
	}
 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!nprime[a[i]+a[j]]){
				cout << 2 << endl << a[i] << ' ' << a[j] << endl;
				return 0;
			}
		}
	}
	cout << 1 << endl << a[0] << endl;
}