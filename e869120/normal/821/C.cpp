#include<bits/stdc++.h>
using namespace std;
int n;string s[900000];
int p[900000],c=1,cnt;stack<int>S;

int main(){
	cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>s[i];
		if(s[i]=="add"){
			cin>>p[i];S.push(p[i]);
		}
		else {
			if(!S.empty() && S.top()!=c){
				cnt++;
				while(!S.empty())S.pop();
			}
			else {if(!S.empty())S.pop();}
			c++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}