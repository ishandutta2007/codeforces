#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n;
int r;
int done=1;

pair <int,int> tempo(int x,int y){
	//~ cout << x << " " << y << endl;
	if(x>=y){
		if(x%y==0){
			if(y==1)return make_pair(x,x-1);
			else return make_pair(INF,INF);
		}
		pair <int,int> next=tempo(x%y,y);
		int num=x/y;
		next.first+=num;
		next.second+=num-1;
		return next;
	}
	if(y%x==0){
		if(x==1){
			return make_pair(y,y-2);
		}
		else return make_pair(INF,INF);
	}
	pair <int,int> next=tempo(x,y%x);
	int num=y/x;
	next.first+=num;
	next.second+=num-1;
	return next;
}

int main(){
	cin >> n >> r;
	if(r==1){
		if(n==1)cout << "0\nT";
		else cout << "IMPOSSIBLE";
		return 0;
	}
	int minimo=INF;
	int chos=0;
	for(int i=1;i<r;i++){
		pair <int,int> ris=tempo(i,r-i);
		if(ris.first==n-1 and ris.second<minimo){
			minimo=ris.second;
			chos=i;
		}
	}
	if(chos==0){
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << minimo;
	cout << endl;
	vector <char> roba;
	int x=chos;
	int y=r-chos;
	while(x>0){
		if(x==1 and y==1){
			x=0;
			roba.push_back('T');
		}
		else if(x>y){
			roba.push_back('T');
			x-=y;
		}
		else if(x<y){
			roba.push_back('B');
			y-=x;
		}
	}
	for(int i=int(roba.size())-1;i>=0;i--)cout << roba[i];
	if(roba[0]=='T')cout << 'B';
	else cout << 'T';
	//~ cout << tempo(1,3).second;
}