#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const int BAS = 146527;
typedef long long LL;
set<LL>ex;
int n;
char s[maxn];
char ok[maxn];
LL get_Hash(int l,int r){
	LL temp = 0;
	LL bas = 1;
	for (int i=l;i<r;i++){
		temp = temp*BAS+(ok[i]-'a'+1);
	}
	return temp;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		memset(s,0,sizeof s);
		memset(ok,0,sizeof ok);
		scanf("%s",s);
		int r = 800;
		int l = r;
		for (int i=strlen(s)-1;i>=0;){
			char now = s[i];
			if (now=='h'){
				int temp = i-1;
				while (temp>=0&&s[temp]=='k')temp--;
				ok[--l] = s[i--];
				i = temp;
			}else if (now=='u'){
				ok[--l] ='o';
				ok[--l] ='o';
				i--;
			}else{
				ok[--l] = s[i--];
			}
		}
//		cout<<"ok: "<<ok+l<<endl;
		LL flag = get_Hash(l,r);
		ex.insert(flag);
	}
	cout<<ex.size()<<endl;
	return 0;
}