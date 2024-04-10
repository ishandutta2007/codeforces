#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
char A[100100];
void run(){
	int n;
	cin>>n;
	char str[100];
	char S[1000000]={0};
	stack<int> st;
	int m=0;
	for(int i=0;;i++){
		if(scanf(" %s",str)!=1){
			break;
		}
		A[i]=str[0];
		m++;
	}
	if(n==1&&m==1){
		puts("int");
		return;
	}
	int pos=0;
	for(int i=0;i<m;i++){
		if(A[i]=='p'){
			st.push(0);
			strcpy(S+pos,"pair<");
			pos+=5;
		}else{
			if(st.empty()){
				puts("Error occurred");
				return;
			}
			if(st.top()==0){
				st.push(1);
				strcpy(S+pos,"int,");
				pos+=4;
			}else{
				strcpy(S+pos,"int>");
				pos+=4;
				st.pop();
				st.pop();
				while(!st.empty() && st.top()!=0){
					st.pop();
					st.pop();
					S[pos++]='>';
				}
				if(st.empty() && i!=m-1){
					puts("Error occurred");
					return;
				}
				if(i!=m-1){
					st.push(1);
					S[pos++]=',';
				}
			}
		}
	}
	if(!st.empty()){
		puts("Error occurred");
		return;
	}
	printf("%s",S);
}
int main(){
	run();
	return 0;
}