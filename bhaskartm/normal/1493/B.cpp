#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int h, m;
int x1, x2, y11, y2;

int rev(int x){
	if(x==1 || x==0 || x==8){
		return x;
	}
	if(x==2){
		return 5;
	}
	if(x==5){
		return 2;
	}
}

bool val(){
	vector<int>vec;
	vec.pb(x1);
	vec.pb(x2);
	vec.pb(y11);
	vec.pb(y2);
	for(auto u:vec){
		if(u==3 || u==4 || u==6 || u==7 || u==9){
			return 0;
		}
	}
	int min=10*rev(x2)+rev(x1);
	int hour=10*rev(y2)+rev(y11);
	if(min<m && hour<h){
		return 1;
	}
	else{
		return 0;
	}
}

void f(){
	if((10*y11+y2)!=(m-1)){
		int ne=(10*y11+y2+1);
		y11=ne/10;
		y2=ne%10;
		return;
	}
	y11=0;
	y2=0;
	int ne=10*x1+x2;
	if(ne==(h-1)){
		x1=0;
		x2=0;
		return;
	}
	else{
		ne+=1;
		x1=ne/10;
		x2=ne%10;
		return;
	}
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>h>>m;
		string st;
		cin>>st;
		x1=st[0]-'0';
		x2=st[1]-'0';
		y11=st[3]-'0';
		y2=st[4]-'0';
		while(1){
			if(val()){
				break;
			}
			else{
				f();
			}
		}
		cout<<x1<<x2<<":"<<y11<<y2<<endl;
	}
	return 0;
}