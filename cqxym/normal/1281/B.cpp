#include<iostream>
using namespace std;
#define R register int
int main(){
	int t;
	cin>>t;
	for(R q=0;q<t;q++){
		string s1,s2;
		cin>>s1>>s2;
		int l=s1.length();
		string mn=s1;
		char smn=s1[l-1];
		int id=l-1;
		for(R i=l-2;i>-1;i--){
			if(s1[i]<smn){
				smn=s1[i];
				id=i;
			}else if(s1[i]>smn){
				swap(s1[i],s1[id]);
				if(s1<mn){
					mn=s1;
				}
				swap(s1[i],s1[id]);
			}
		}
		if(mn<s2){
			cout<<mn;
		}else{
			cout<<"---";
		}
		puts("");
	}
	return 0;
}