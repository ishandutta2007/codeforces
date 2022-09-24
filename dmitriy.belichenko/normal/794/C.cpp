#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
long long m;
using namespace std;

string s,t,ans;
int n;

int main()
{
   
    cin >> s;
    cin >> t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    n = s.size();
    ans.resize(n,'a');
    int l = 0 , r = s.size() - 1 ;
    int ls=0 , rs=(n-1)/2, lt=0, rr = (n-2)/2;
    for(int i=0; i<n; i++)
    {
        if(i % 2 == 1)
        {
            if(s[ls]<t[lt])
            {
                ans[l++]=t[lt++];
            }
            else
            {
                ans[r--]=t[rr--];
            }
        }
        else
        {
            if( s[ls] < t[lt] )
            {
                ans[l++]=s[ls++];
            }
            else
            {
                ans[r--]=s[rs--];
            }
        }
    }
     cout << ans << "\n";
}