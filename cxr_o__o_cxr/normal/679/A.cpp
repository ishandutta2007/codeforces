#include<bits/stdc++.h>
using namespace std;
int pri[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
char s[8];
int main(){
	int fl=1,cnt=0;
	for(int i=0;i<=18;i++){
		cout<<pri[i]<<"\n";
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='y'){
			cnt++;
			if(cnt>1){
				fl=0;
				break;
			}
		}
	} 
	if(fl)cout<<"prime\n";
	else cout<<"composite\n";
	return (0-0);
}