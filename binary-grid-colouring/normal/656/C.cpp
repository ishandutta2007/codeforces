#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
  	int p1='@',p2='[',p3='`',p4='{';
  	
    string s;
    cin>>s;
    int len=s.length();
    
    int res=0;
    for(int i=0;i<len;i++)
	{
        if (!isalpha(s[i])) continue ;
        int ind=tolower(s[i])-'a'+1;
        int k1=0,k2=0;      
        if (p1<s[i] && p2>s[i]) k1=ind;
        if (p3<s[i] && p4>s[i]) k2=ind;
        res += k1-k2;
    }
    cout<<res<<endl;
    return 0;
}