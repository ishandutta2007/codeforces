#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    string s1[m],s2[m],s;
    for(i=0;i<m;i++)
    cin>>s1[i]>>s2[i];
    for(i=0;i<n;i++)
    {
        cin>>s;
        for(j=0;j<m;j++)
        {
            if(s.compare(s1[j])==0)
            (s1[j].length()<=s2[j].length())?cout<<s1[j]:cout<<s2[j];
        }
        cout<<" ";
    }
    return 0;
}