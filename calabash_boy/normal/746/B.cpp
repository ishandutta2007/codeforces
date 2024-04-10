#include<iostream>
using namespace std;
int main(){
	char data[2005];
	char ans[2005];
	int n;
	int cnt;
	cin>>n;
	cnt=n;
	int lptr,rptr;
		for (int i=1;i<=n;i++){
		cin>>data[i];
	}
	if (!(n&1)){
		lptr=n>>1;
		rptr=lptr+1;
		cnt=1;
	}else{
		lptr=n>>1;
		//cout<<lptr<<endl;
		ans[lptr+1]=data[1];
		//cout<<data[1]<<endl;
		rptr=(n>>1)+2;
		cnt=2;
	}
	bool l=1;
	for (int i=cnt;i<=n;i++){
		if (l){
			ans[lptr]=data[i];
			lptr--;
			l=0;
		}else{
			ans[rptr]=data[i];
			rptr++;
			l=1;
		}
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i];
	}
	return 0;
}