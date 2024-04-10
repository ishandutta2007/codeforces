#include<cstdio>
#include<iostream>
using namespace std;
bool q[10];
int main(){
	int n,i,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	for(i=0;i<n;i++){
		if(s[i]=='L'){
			j=0;
			while(q[j]==true){
				j++;
			}
			q[j]=true;
		}else if(s[i]=='R'){
			j=9;
			while(q[j]==true){
				j--;
			}
			q[j]=true;
		}else{
			q[s[i]-48]=false;
		}
	}
	for(i=0;i<=9;i++){
		printf("%d",q[i]);
	}
	return 0;
}