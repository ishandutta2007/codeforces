#include<bits/stdc++.h>
using namespace std;
int n;
const int MAX = 2000;
char temp [MAX];
int main(){
	cin>>n;
	int ans = -1;
	while (scanf("%s",temp)!=EOF){
		int len = strlen(temp);
		int tempAns = 0;
		for (int i = 0;i<len;i++){
			if (temp[i]>='A'&&temp[i]<='Z'){
				tempAns++;
			}
		}
		ans = max(ans,tempAns);
	}
	cout<<ans<<endl;
	return 0;
}