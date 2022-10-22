#include<iostream>
using namespace std;
const int N=300005;
int n;
char a[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	int cnt1=0,cnt2=0,cnt3=0;
	if(n&1){
		cout<<":(";
		return 0;
	}
	for(i=1;i<=n;i++){
		if(a[i]=='(') cnt1++;
		else if(a[i]==')') cnt2++;
		else cnt3++;
	}
	int k=0;
	if(cnt1+cnt3<cnt2||cnt2+cnt3<cnt1){
		cout<<":(";
		return 0;
	}
	int cnt=0,num=(cnt3+cnt2-cnt1)/2;
	for(i=1;i<=n;i++){
		if(a[i]=='(') k++;
		else if(a[i]==')') k--;
		else{
			if(cnt<num){
				a[i]='(';
				cnt++;
				k++;
			}
			else{
				a[i]=')';
				k--;
			}
		}
		if(i!=n&&k<=0){
			cout<<":(";
			return 0;
		}
	}
	for(i=1;i<=n;i++) cout<<a[i];
	return 0;
}