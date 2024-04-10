#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int n,m;
char s[10005];
int main(){
	cin>>n;
	gets(s);
	gets(s);
	int len=0,cur=0,ans=1;
	for(int i=0;s[i];i++){
		len++;
		if(s[i]=='.' || s[i]=='?' || s[i]=='!'){
			if(len>n){
				cout<<"Impossible\n";
				return 0;
			}
			if(int(cur>0)+cur+len>n){
				cur=0;
				ans++;
			}
			cur+=len+int(cur>0);
			len=-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}