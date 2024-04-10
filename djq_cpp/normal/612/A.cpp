#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int n,x,y;
	string s;
	scanf("%d%d%d",&n,&x,&y);
	cin>>s;
	if(x<y)swap(x,y);
	if(x){
		int p=n%x;
		for(int k=0;k<x;k++){
			if((y*k)%x==p&&y*k<=s.length()){
				int now=0;
				printf("%d\n",k+(n-y*k)/x);
				for(int t=0;t<k&&now<s.length();t++){
					cout<<s.substr(now,y)<<endl;
					now+=y;
				}
				for(;now<s.length();now+=x)
				cout<<s.substr(now,x)<<endl;
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}