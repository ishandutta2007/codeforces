#include<bits/stdc++.h>

using namespace std;

const int maxn=1505;

int n;
int m;
int l,r;
int x[maxn];
long long niv;
bool oe;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(x[i]>x[j])niv++;
		}
	}
	//cout<<niv;
	oe=niv%2;
	cin>>m;
	while(m--){
		cin>>l>>r;
		long long chk=(r-l+1)*(r-l)/2;
		if(chk%2==1){
			oe=!oe;
		}
		if(!oe){
			cout<<"even"<<endl;
		}else{
			cout<<"odd"<<endl;
		}
	}
	return 0;
}