#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if (n%4){
		cout<<"===";
		return 0;
	}
	n/=4;
	char data[300];
	int acnt=0,ccnt=0,gcnt=0,tcnt=0,qcnt=0;
	for (int i=1;i<=4*n;i++){
		cin>>data[i];
		if (data[i]=='A') acnt++;
		if (data[i]=='C') ccnt++;
		if (data[i]=='G') gcnt++;
		if (data[i]=='T') tcnt++;
		if (data[i]=='?') qcnt++;
	}
	if (acnt>n||ccnt>n||gcnt>n||tcnt>n){
		cout<<"===";
		return 0;
	}
	acnt=n-acnt;
	ccnt=n-ccnt;
	tcnt=n-tcnt;
	gcnt=n-gcnt;
//	cout<<acnt<<' '<<ccnt<<' '<<gcnt<<' '<<tcnt<<endl;
	for (int i=1;i<=4*n;i++){
		if (data[i]=='?'){
			if (acnt){
				data[i]='A';
				acnt--;
			}else if (ccnt){
				data[i]='C';
				ccnt--;
			}else if (tcnt){
				data[i]='T';
				tcnt--;
			}else if (gcnt){
				data[i]='G';
				gcnt--;
			}
		}
	}
	for (int i=1;i<=4*n;i++)
		cout<<data[i];
	return 0;
}