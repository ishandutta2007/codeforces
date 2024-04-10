#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s1, s2, s3, s4;
    cin>>s1>>s2;
    int n;
    cin>>n;
    cout<<s1<<" "<<s2<<"\n";
    for(int a=0; a<n; a++)
    {
        cin>>s3>>s4;
        if(s1==s3) s1=s4;
        else s2=s4;
        cout<<s1<<" "<<s2<<"\n";
    }
}