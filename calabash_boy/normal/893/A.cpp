#include<bits/stdc++.h>
using namespace std;
bool alive[5];
int n;
int main(){
	alive[1]=alive[2]=1;
	alive[3]=0;
	scanf("%d",&n);
	while (n--){
		int x;
		scanf("%d",&x);
		if (alive[x]){
			for (int i=1;i<=3;i++){
				if (i!=x)alive[i] = !alive[i];
			}
		}else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}