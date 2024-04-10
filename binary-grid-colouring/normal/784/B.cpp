#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
    long long m, n;
    vector<int> v;
    char s[] = "0123456789ABCDEF";
    cin>>n;
    v.clear();
    if (n == 0)
            v.push_back(0);

        while (n != 0)
        {
            v.push_back(n%16);
            n = n / 16;
        }
		long long ans=0; 
        vector<int>::iterator rit;
        for (rit = v.begin(); rit != v.end(); rit++)
        {
        //	cout<<s[*rit];
        	if(s[*rit]=='0')ans++;
        	else if(s[*rit]=='6') ans++;
        	else if(s[*rit]=='4') ans++;
        	else if(s[*rit]=='8')ans+=2;
        	else if(s[*rit]=='9') ans++;
        	else if(s[*rit]=='A') ans++;
        	else if(s[*rit]=='B')ans+=2;
        	else if(s[*rit]=='D') ans++;
        	else if(s[*rit]=='0')ans++;
        	
		}
    cout<<ans<<endl;  
    return 0;
}