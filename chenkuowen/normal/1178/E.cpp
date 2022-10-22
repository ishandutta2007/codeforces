#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
char s[N];
vector<int> a;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),m=0;
	int i=1,j=n;
	while(i<=j){
		if(s[i]==s[j]){
			a.push_back(i);
			a.push_back(j);
			i+=1; j-=1;
		}else if(s[i]==s[j-1]){
			a.push_back(i);
			a.push_back(j-1);
			i+=1; j-=2;
		}else if(s[i+1]==s[j]){
			a.push_back(i+1);
			a.push_back(j);
			i+=2; j-=1;
		}else ++i,--j;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i=0;i<a.size();++i) putchar(s[a[i]]);
	return 0;
}