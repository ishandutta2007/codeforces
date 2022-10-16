#include<bits/stdc++.h>
using namespace std;
int a[2],x;
bool vec=0;
vector<string>ans;
int main(){
	cin>>a[0]>>a[1]>>x;
	if(a[0]<a[1])vec=1;
	if(x==1){
		for(int i=0;i<a[0];i++)cout<<0;
		for(int i=0;i<a[1];i++)cout<<1;
		return 0;
	}
	while(x){
		if(x==1&&(a[0]&&a[1]))
		{
			for(int i=0;i<a[vec];i++)cout<<vec;
			for(int i=0;i<a[!vec];i++)cout<<!vec;
			return 0;
		}
		cout<<vec;
		x--;
		a[vec]--;
		vec=!vec;
	}
}