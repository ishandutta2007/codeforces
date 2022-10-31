#include<bits/stdc++.h>
using namespace std;
const int maxn = 5050;
char s[maxn];
int n;
int cnt[26][26][maxn];
int main(){
	scanf("%s",s);
	n = strlen(s);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i!=j){
				cnt[s[i]-'a'][s[j]-'a'][(i-j+n)%n]++;
			}
		}
	}
	int ans =0;
	for (int i=0;i<26;i++){
		int tempAns =0;
		for (int l=1;l<n;l++){
			int temp =0;
			for (int j=0;j<26;j++){
				temp+=cnt[i][j][l]==1;
			}
			tempAns = max(tempAns,temp);
		}
		ans+=tempAns;
	}
	printf("%.9f\n",1.0*ans/n);
	return 0;
}