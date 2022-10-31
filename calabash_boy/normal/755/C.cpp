#include<iostream>
using namespace std;
int father [10005];
int f(int a){
	if (father[a]==a){
		return a;
	}else{
		return f(father[a]);
	}
}
void un(int a,int b){
	int fa=f(a);
	int fb=f(b);
	if (fa==fb){
		return;
	}else{
		int ff=a;
		while(ff!=fa){
			int temp=father[ff];
			father[ff]=fb;
			ff=temp;
		}
		father[fa]=fb;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		un(i,temp);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if (father[i]==i){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}