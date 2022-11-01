#include<bits/stdc++.h>
using namespace std;
string s[500005];
int main()
{
	int n;
	string ss;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i = n-1; i > 0 ; --i){
		
		if(s[i] < s[i-1]){ 
			ss = s[i-1];
			s[i-1] = "";
			for(int j = 0; ss[j] <= s[i][j]; j++){
				s[i-1] += ss[j];
			}
		}
	}
	for(int i=0;i<n;i++) cout<<s[i]<<endl;
	return 0;
}