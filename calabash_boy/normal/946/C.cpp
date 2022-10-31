#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+100;
char s[maxn];
int n;
int main(){
	scanf("%s",s);
	n = strlen(s);
	int now='a';
	for (int i=0;i<n&&now<='z';i++){
		if (s[i]<=now){
			s[i] = now++;
		}
	}
	if (now=='z'+1){
		printf("%s\n",s);
	}else{
		cout<<-1<<endl;
	}
	return 0;
}