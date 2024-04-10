#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3,s4="mps";
	int cnt=0;
	cin>>s1>>s2>>s3;
	if(s1[1]!=s2[1]&&s2[1]!=s3[1]&&s1[1]!=s3[1]){
		cout<<2;
		return 0;
	}
	if(s1>s2)swap(s1,s2);
	if(s1>s3)swap(s1,s3);
	if(s2>s3)swap(s2,s3);
	for(int i=1;i<=7;i++)
		for(int j=0;j<3;j++)
			cnt=max(cnt,(s1[0]==i+'0'&s1[1]==s4[j])+(s2[0]==i+'1'&s2[1]==s4[j])+(s3[0]==i+'2'&s3[1]==s4[j])),
			cnt=max(cnt,(s2[0]==i+'0'&s2[1]==s4[j])+(s1[0]==i+'1'&s1[1]==s4[j])+(s3[0]==i+'2'&s3[1]==s4[j])),
			cnt=max(cnt,(s1[0]==i+'0'&s1[1]==s4[j])+(s3[0]==i+'1'&s3[1]==s4[j])+(s2[0]==i+'2'&s2[1]==s4[j])),
			cnt=max(cnt,(s2[0]==i+'0'&s2[1]==s4[j])+(s3[0]==i+'1'&s3[1]==s4[j])+(s1[0]==i+'2'&s1[1]==s4[j])),
			cnt=max(cnt,(s3[0]==i+'0'&s3[1]==s4[j])+(s1[0]==i+'1'&s1[1]==s4[j])+(s2[0]==i+'2'&s2[1]==s4[j])),
			cnt=max(cnt,(s3[0]==i+'0'&s3[1]==s4[j])+(s2[0]==i+'1'&s2[1]==s4[j])+(s1[0]==i+'2'&s1[1]==s4[j]));
	cout<<min(3-cnt,2-(s1==s2)-(s2==s3));
}