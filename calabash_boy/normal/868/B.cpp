#include<bits/stdc++.h>
using namespace std;
int h,m,s,t1,t2;
bool flag [100000];
int main(){
	cin>>h>>m>>s>>t1>>t2;
	flag[(s*720)%43200]=true;
	flag[(m*720+s*12)%43200]=true;
	flag[(h*3600+m*60+s)%43200]=true;
	t1 = (t1*3600)%43200;
	t2 =(t2*3600)%43200;
	int temp = t1;
	bool succ = true;
	while (temp!=t2){
		temp++;
		temp%=43200;
		if (temp==t2)break;
		if (flag[temp]){
			succ = false;
			break;
		}
	}
	if (succ){
		cout<<"YES"<<endl;
		return 0;
	}
	succ = true;
	temp =t1;
	while (temp!=t2){
		temp+=43199;
		temp%=43200;
//		cout<<temp<<endl;
		if (temp==t2){
			break;
		}
		if (flag[temp]){
			succ = false;
			break;
		}
	}
	if (succ){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}