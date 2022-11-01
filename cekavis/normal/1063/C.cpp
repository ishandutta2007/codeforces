#include<iostream>
#include<string>
using namespace std;
int n;
string col, col0;
int main() {
	cin>>n;
	cout<<"0 0"<<endl;
	cin>>col0;
	int l=1, r=1e9;
	for(int i=1; i<n; ++i){
		int mid=l+r>>1;
		cout<<mid<<' '<<mid<<endl;
		cin>>col;
		if(col==col0) l=mid+1; else r=mid-1;
	}
	cout<<l<<' '<<l-1<<' '<<l-1<<' '<<l<<endl;
	return 0;
}