#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define TP int
string s1,s2;
int main()
{
	cin>>s1>>s2;
	sort(s1.begin(),s1.end());
	if(s1[0]=='0')
        for(int i=1;i<s1.length();i++) 
            if(s1[i]!='0'){
				swap(s1[0],s1[i]);
				break;
			}
	if(s2==s1)
		cout<<"OK"<<endl;
    else
		cout<<"WRONG_ANSWER"<<endl;
    return 0;
}