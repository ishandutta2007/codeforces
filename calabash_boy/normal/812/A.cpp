#include<bits/stdc++.h>
using namespace std;
int main(){
	int l[4],r[4],s[4],flag[4];
	for (int i=0;i<4;i++){
		cin>>r[i]>>s[i]>>l[i]>>flag[i];
	}
	for (int i=0;i<4;i++){
		if (flag[i]){
			if (l[i]||r[i]||s[i]){
				cout<<"YES"<<endl;
				return 0;
			}
			if (r[(i+1)%4]||s[(i+2)%4]||l[(i+3)%4]){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}