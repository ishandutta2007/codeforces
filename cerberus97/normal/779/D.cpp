#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
bool isPossible( string s, char t[200001] ){
	bool ans = false;
	int index = 0;
	int check = 0;
	int len_s = s.length(), len_t = strlen(t);
	for(int i=0; i<len_s; i++){
		if(t[index]==s[i]){
			check++;
			index++;
			if(index >= len_t)
				break;
		}	
	}
	return check==len_t;
	
}

string rSmallString(char s[200001], int a[200001],int l	){
	int hash[200001]={0};
	for(int i=0;i<=l; i++){
		hash[a[i]]=1;
	}
	string t;
	int j = 0, len = strlen(s);
	for(int i=0;i<len;i++){
		if(hash[i+1]==0){
			t += s[i];
		}
	}
	
	return t;		
}
int main(){
	char s[200001];
	char t[200001];
	int p[200001];
	cin>>s;
	cin>>t;
	int n = strlen(s);
	for(int i=0; i<n; i++){
		cin>>p[i];
	}
	int l=0;
	int h=strlen(s)-1;
	int mid=(l+h)/2;
	int i;
	while(l<=h){ 
		//cout<<mid<<" "<<rSmallString(s,p,mid)<<endl;

		if(isPossible(rSmallString(s,p,mid),t)){
			l=mid+1;
			mid=(l+h)/2;
		}
		else{
			h=mid-1;
			mid=(h+l)/2;
		}
		
	}
	cout<<l;	
	return 0;

	// string s = "abc";
	// s[] = 'd';
	// cout << s;
}