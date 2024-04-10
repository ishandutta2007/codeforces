#include<iostream>
#include<vector>

using namespace std;

typedef vector<bool> VB;

int main(){
	int n,p,q;
	cin>>n;
	VB f(n+1,false);
	cin>>p;
	for(int i = 0;i < p;++i){
		cin>>q;
		if(!f[q]){
			f[q] = true;
			--n;
		}
	}
	cin>>p;
	for(int i = 0;i < p;++i){
		cin>>q;
		if(!f[q]){
			f[q] = true;
			--n;
		}
	}
	if(n == 0) cout<<"I become the guy."<<endl;
	else cout<<"Oh, my keyboard!"<<endl;
}