#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int l,i,ct1=0,ct2=0;
	scanf("%d\n",&l);
	char c;
	stack<bool>Q;
	for(i=0;i<l;i++){
		scanf("%c",&c);
		if(c=='('){
			ct1++;
			Q.push(false);
		}else{
			ct2++;
			if(Q.empty()==false&&Q.top()==false){
				Q.pop();
			}else{
				Q.push(true);
			}
		}
	}
	if(ct1!=ct2||Q.size()>2){
		printf("No");
	}else{
		printf("Yes");
	}
	return 0;
}