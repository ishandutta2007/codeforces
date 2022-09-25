#include<bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	loopi(noob,n){
		string str;
		cin >> str;
		bool b=false;
		int x=0;
		int y=0;
		int z;
		loop(str.size()){
			z=int(str[i]-'0');
			if(z==0) b=true;
			if(z%2==0) x++;
			y+=z%3;
		}
		if(!b){
			cout << "cyan\n";
			continue;
		}
		if(x<=1){
			cout << "cyan\n";
			continue;
		}
		if(y%3!=0){
			cout << "cyan\n";
			continue;
		}
		cout << "red\n";
	}
	return 0;
}