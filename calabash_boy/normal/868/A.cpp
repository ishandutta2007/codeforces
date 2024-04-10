#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char word[maxn][5];
char pas[maxn];
bool ok(int x,int y){
	if (word[x][1]==pas[0]&&word[y][0]==pas[1])return true;
	return false;
}
int main(){
	scanf("%s",pas);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",word[i]);
		if (word[i][0]==pas[0]&&word[i][1]==pas[1]){
			cout<<"YES"<<endl;
			return 0;
		}
		for (int j=1;j<=i;j++){
			if (ok(i,j)||ok(j,i)){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}