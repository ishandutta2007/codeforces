#include <bits/stdc++.h>
using namespace std;
int T;string s;
int main(){
	cin>>T;
	while(T--)cin>>s,sort(s.begin(),s.end()),cout<<s.back()-'0'<<"\n";
}