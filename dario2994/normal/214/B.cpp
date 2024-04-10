#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector <short int> cifre;
	int s=0;
	int uno=0;
	int due=0;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		cifre.push_back(x);
		if(x%3==1)uno++;
		if(x%3==2)due++;
		s+=x;
	}
	s%=3;
	sort(cifre.begin(),cifre.end());
	if(cifre[0]!=0){
		cout << -1;
		return 0;
	}
	if(s==1){
		if(uno>=1){
			int aggiust=1;
			for(int i=0;i<n;i++){
				if(cifre[i]%3==1 and aggiust>0){
					cifre[i]=-1;
					aggiust--;
				}
			}
		}
		else if(due>=2){
			int aggiust=2;
			for(int i=0;i<n;i++){
				if(cifre[i]%3==2 and aggiust>0){
					cifre[i]=-1;
					aggiust--;
				}
			}
		}
		else{
			cout << -1;
			return 0;
		}
	}
	if(s==2){
		if(due>=1){
			int aggiust=1;
			for(int i=0;i<n;i++){
				if(cifre[i]%3==2 and aggiust>0){
					cifre[i]=-1;
					aggiust--;
				}
			}
		}
		else if(uno>=2){
			int aggiust=2;
			for(int i=0;i<n;i++){
				if(cifre[i]%3==1 and aggiust>0){
					cifre[i]=-1;
					aggiust--;
				}
			}
		}
		else {
			cout << -1;
			return 0;
		}
	}
	bool first=true;
	for(int i=n-1;i>=0;i--){
		if(cifre[i]>=0){
			if(first==true and cifre[i]==0){
				cout << 0;
				return 0;
			}
			first=false;
			cout << cifre[i];
		}
	}
}