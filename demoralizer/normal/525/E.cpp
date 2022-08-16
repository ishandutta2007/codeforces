#include "bits/stdc++.h"
using namespace std;

int a[30];
long long factorial[20];

map<pair<long long, int>, int> count_first_half;

int main(){
	factorial[0] = 1;
	for(int i = 1; i < 20 ; i++){
		factorial[i] = i * factorial[i-1];
	}
	
	int n,k;
	long long s;
	cin>>n>>k>>s;
	
	for(int i = 0; i < n; i++)
		cin>>a[i];
	
	int top = 1;
	
	for(int i = 0; i < n/2; i++){
		top *= 3;
	}
	
	for(int i = 0; i < top; i++){
		int x = i;
		int two_count = 0;
		long long temp = 0;
		bool ok = 1;
		for(int j = 0; j < n/2; j++){
			int current = x % 3;
			if(current == 1) temp += a[j];
			if(current == 2){
				if(a[j] > 19) ok = 0;
				else temp += factorial[a[j]];
				two_count++;
			}
			x /= 3;
		}
		if(two_count > k) ok = 0;
		if(temp > s) ok = 0;
		if(ok){
			count_first_half[{temp,two_count}]++;
		}
	}
	
	top = 1;
	
	for(int i = n/2; i < n; i++){
		top *= 3;
	}
	
	long long answer = 0;
	
	for(int i = 0; i < top; i++){
		int x = i;
		int two_count = 0;
		long long temp = 0;
		bool ok = 1;
		for(int j = n/2; j < n; j++){
			int current = x % 3;
			if(current == 1) temp += a[j];
			if(current == 2){
				if(a[j] > 19) ok = 0;
				else temp += factorial[a[j]];
				two_count++;
			}
			x /= 3;
		}
		if(two_count > k) ok = 0;
		if(temp > s) ok = 0;
		if(ok){
			long long difference = s - temp;
			for(int z = 0; z <= k - two_count; z++){
				if(count_first_half.count({difference,z}))
					answer += count_first_half[{difference,z}];
			}
		}
	}
	
	cout<<answer;
	
}