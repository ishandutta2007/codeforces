#include<bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	priority_queue<int> pq;
	scanf("%s",s);
	int sum0=0,sum1=0,tot=0;
	for (int i=0;i<3;i++){
		sum0+=s[i]-'0';
	}
	for (int j=3;j<6;j++){
		sum1+=s[j]-'0';
	}
	if (sum0==sum1){
		cout<<"0"<<endl;
		return 0;
	}
	int tar ;
	if (sum0<sum1){
		tar = sum1-sum0;
		for (int i=0;i<3;i++){
			pq.push('9'-s[i]);
		}
		for (int i=3;i<6;i++){
			pq.push(s[i]-'0');
		}
	}else{
		tar = sum0-sum1;
		for (int i=0;i<3;i++){
			pq.push(s[i]-'0');
		}
		for (int i=3;i<6;i++){
			pq.push('9'-s[i]);
		}
	}
	while (tar>0){
		tar -=pq.top();
		pq.pop();
		tot++;
	}
	cout<<tot<<endl;
	return 0;
}