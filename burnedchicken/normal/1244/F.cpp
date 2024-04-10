#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int n,k,sta,it;
	string str;
	cin >> n >> k >> str;
	bool good[n];
	int dist[n];
	loop(n){
		if(str[(i+1)%n]==str[i%n]){
			sta=i;
			break;
		}
		if(i==n-1){
			if(k%2==1){
				for(int j=0; j<n; j++){
					if(str[j]=='W') str[j]='B';
					else str[j]='W';
				}
			}
			for(int j=0; j<n; j++){
				cout << str[j];
			}
			cout << endl;
			return 0;
		}
	}
	loop(n){
		good[i]=false;
	}
	loop(n){
		if(str[(i+1)%n]==str[i%n]){
			good[(i+1)%n]=good[i%n]=true;
		}
	}
	it=0;
	for(int i=sta; i<sta+n; i++){
		if(good[i%n]){
			dist[i%n]=0;
			it=0;
		}
		else{
			it++;
			dist[i%n]=it;
		}
	}
	it=0;
	for(int i=sta+n+1; i>sta+1; i--){
		if(good[i%n]){
			dist[i%n]=0;
			it=0;
		}
		else{
			it++;
			dist[i%n]=min(it, dist[i%n]);
		}
	}
	loop(n){
		if(min(dist[i],k)%2==1){
			if(str[i]=='W') str[i]='B';
			else str[i]='W';
		}
	}
	loop(n){
		cout << str[i];
	}
	cout << endl;
	return 0;
}