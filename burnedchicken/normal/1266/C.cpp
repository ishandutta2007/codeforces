#include<bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int r,c;
	cin >> r >> c;
	if(r==1&&c==1){
		cout << "0\n";
		return 0;
	}
	if(c==1){
		loop(r) cout << i+2 << "\n";
		return 0;
	}
	loop(r){
		loopi(j,c){
			cout << (i+1)*(r+j+1) << " ";
		}
		cout << "\n";
	}
	return 0;
}