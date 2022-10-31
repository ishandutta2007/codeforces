#include<iostream>
#include<set>
using namespace std;
int main(){
	set <string> name;
	int m,n;
	int num,com=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		string temp;
		cin>>temp;
		name.insert(temp);
	}
	for(int i=1;i<=n;i++){
		string temp;
		num=name.size();
		cin>>temp;
		name.insert(temp);
		if (num==name.size()){
			com++;
		}
	}
	if (com&1==1){
		n--;
	}
	if (m>n){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}