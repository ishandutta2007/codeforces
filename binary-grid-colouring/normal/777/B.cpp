#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	cin>>n;
	string s,ss;
	cin>>s>>ss;
	sort(s.begin(),s.end());
	sort(ss.begin(),ss.end());
	int j=n-1;
	for(int i=n-1;i>=0;--i){
		if(ss[j]>=s[i]) --j;
	}
	cout<<j+1<<endl;
	j=0;
	for(int i=0;i<n;i++){
		if(ss[i]>s[j])j++;
	}
	cout<<j<<endl;
	return 0;
}