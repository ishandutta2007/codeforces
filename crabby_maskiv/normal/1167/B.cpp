#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[10]={0,4,8,15,16,23,42};
int c[10];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	for(i=1;i<=4;i++){
		cout<<"? "<<i<<" "<<i+1<<endl;
		fflush(stdout);
		cin>>c[i];
	}
	cout<<"!"<<endl;
	fflush(stdout);
	if(a[1]*a[2]==c[1]&&a[2]*a[3]==c[2]&&a[3]*a[4]==c[3]&&a[4]*a[5]==c[4]){
		for(i=1;i<=6;i++){
			cout<<a[i]<<" ";
			fflush(stdout);
		}
		return 0;
	}
	while(next_permutation(a+1,a+7)){
		if(a[1]*a[2]==c[1]&&a[2]*a[3]==c[2]&&a[3]*a[4]==c[3]&&a[4]*a[5]==c[4]){
			for(i=1;i<=6;i++) cout<<a[i]<<" ";
			return 0;
		}	
	}
	return 0;
}