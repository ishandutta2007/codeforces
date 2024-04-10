#include<iostream>
using namespace std;

int main()
{
	int n,k,bal[27]={0};
	char c;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> c;
		bal[c-'a']++;
	}
	int flag = 0;
	
	for(int i=0;i<26;i++){
		if(bal[i]>k)
			flag = 1;
	}
	
	if(flag){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
 }