#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y;
    string re;
    cin>>n;
    x=n, y=n;
    vector <char> anl, anr;
    for(int a=0; a<n-1; a++)
    {
        cout<<"? "<<1<<" "<<1<<" "<<x-1<<" "<<y<<"\n";
        cin>>re;
        if(re=="YES")
        {
            x--, anr.push_back('D');
        }
        else
        {
            y--, anr.push_back('R');
        }
    }
    x=1, y=1;
    for(int a=0; a<n-1; a++)
    {
        cout<<"? "<<x<<" "<<y+1<<" "<<n<<" "<<n<<"\n";
        cin>>re;
        if(re=="YES")
        {
            y++, anl.push_back('R');
        }
        else
        {
            x++, anl.push_back('D');
        }
    }
    cout<<"! ";
    reverse(anr.begin(), anr.end());
    for(int a=0; a<n-1; a++) cout<<anl[a];
    for(int a=0; a<n-1; a++) cout<<anr[a];
}