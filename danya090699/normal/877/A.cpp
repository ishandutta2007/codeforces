#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    for(int a=0; a<n; a++)
    {
        if(a+5<=n)
        {
            if(s.substr(a, 5)=="Danil") q++;
            if(s.substr(a, 5)=="Slava") q++;
        }
        if(a+4<=n)
        {
            if(s.substr(a, 4)=="Olya") q++;
        }
        if(a+3<=n)
        {
            if(s.substr(a, 3)=="Ann") q++;
        }
        if(a+6<=n)
        {
            if(s.substr(a, 6)=="Nikita") q++;
        }
    }
    if(q==1) cout<<"YES";
    else cout<<"NO";
}