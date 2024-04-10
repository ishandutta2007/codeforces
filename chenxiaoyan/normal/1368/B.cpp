/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int a[10]={};
	string b="codeforces";
	while(true){
		for(int i=0;i<10;i++){
			a[i]++;
			long long cnt=1;
			for(int j=0;j<10;j++)cnt*=a[j];
			if(cnt>=n){
				for(int j=0;j<10;j++)while(a[j]--)cout<<b[j];
				return 0;
			}
		}
	}
	return 0;
}