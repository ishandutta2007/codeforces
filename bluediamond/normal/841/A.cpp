#include <iostream>
using namespace std;
int ap[35];
int main()
{
    int n,k,i;
    cin>>n>>k;
    cin.get();
    char ch;
    for(i=1;i<=n;i++)
    {
        ch=cin.get();
        ap[ch-'a']++;
    }
    for(i=0;i<26;i++)
        if(ap[i]>k)
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}