#include<iostream>
using namespace std;
int main(){
	char f[200];
	f['L']='R';
	f['R']='L';
	f['U']='D';
	f['D']='U';
	int n;
	cin>>n;
	int ans=1;
	char opt1=0,opt2=0,conf1=0,conf2=0;
	cin>>opt1;
	conf1=f[opt1];
	for (int o=2;o<=n;o++){
		char tmp;
		cin>>tmp;
		if (tmp==conf1||tmp==conf2){
			ans++;
			opt1=tmp;
			conf1=f[opt1];
			opt2=0;
			conf2=0;
		}else{
			if (opt2==0&&opt1!=tmp){
				opt2=tmp;
				conf2=f[opt2];
			}
		}
	}
	cout<<ans;
	return 0;
}