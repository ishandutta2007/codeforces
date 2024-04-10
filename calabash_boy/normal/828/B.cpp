#include<bits/stdc++.h>
using namespace std;
int l=105,r=-1,t=105,b=-1;
int m,n;
int tot;
int main(){
	cin>>n>>m;
	char temp;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>temp;
			if (temp=='B'){
				tot++;
				l=min(l,j);
				r=max(r,j);
				t=min(t,i);
				b=max(b,i);
			}
		}
	}
	if (tot==0){
		cout<<"1"<<endl;
		return 0;
	}
	int length = max((b-t),(r-l))+1;
	if (length>m||length>n){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<length*length-tot<<endl;
	return 0;
}