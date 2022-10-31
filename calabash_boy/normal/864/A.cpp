#include<bits/stdc++.h>
using namespace std;
int num1=-1,num2=-1,n,cnt1,cnt2;
int main(){
	cin>>n;
	while (n--){
		int temp;
		cin>>temp;
		if (num1==-1){
			num1=temp;
			cnt1++;
		}else if (num1==temp){
			cnt1++;
		}else{
			if (num2==-1){
				num2=temp;
				cnt2++;
			}else{
				if (temp!=num2){
					cout<<"NO"<<endl;
					return 0; 
				}else{
					cnt2++;
				}
			}
		}
	}
	if (num2==-1||cnt1!=cnt2){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<num1<<" "<<num2<<endl;
	return 0;
}