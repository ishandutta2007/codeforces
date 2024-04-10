#include<bits/stdc++.h>
using namespace std;
set<char> ans;
int biggest=0;
char s[2000];
bool isUp(char ai){
	if (ai>='A'&&ai<='Z')return true;
	return false;
}
int main(){
	int len;
	scanf("%d",&len);
	scanf("%s",s);
	for (int i=0;i<len;i++){
		if (isUp(s[i])){
			biggest = max(biggest,(int)ans.size());
			ans.clear();
		}else{
			ans.insert(s[i]);
		}
	}
	if (!isUp(s[len-1])){
		biggest = max(biggest,(int)ans.size());
	}
	cout<<biggest<<endl;
}