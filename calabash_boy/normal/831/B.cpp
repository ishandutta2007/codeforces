#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
char key1[MAXN],key2[MAXN],info[MAXN];
int mp[MAXN];
int main(){
	scanf("%s%s%s",key1,key2,info);
	for (int i=0;i<26;i++){
		mp[key1[i]]=i;
	}
	for (int i=0;i<strlen(info);i++){
		bool Cap=false;
		char temp = info[i];
		if (temp>='A'&&temp<='Z'||temp>='a'&&temp<='z'){
			
		}else{
			cout<<temp;
			continue;
		}
		if (temp>='A'&&temp<='Z'){
			Cap=true;
			temp-='A'-'a';
		}
		char target = key2[mp[temp]];
		if (Cap){
			target+='A'-'a';
		}
		cout<<target;
	}
	cout<<endl;
	return 0;
}