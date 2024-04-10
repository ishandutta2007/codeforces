#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,c;
        cin>>s>>c;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<c[i])
                break;
            else{
                bool sm=0;
                for(int j=i+1;j<s.length();j++)
                {
                    if(s[j]<c[i])
                    {
                        sm=1;
                        swap(s[i],s[j]);
                        break;
                    }
                }
                if(sm) break;
                else if(s[i]!=c[i]){
                    for(int j=s.length()-1;j>i;j--)
                    {
                        if(s[j]==c[i])
                        {
                            swap(s[j],s[i]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(s<c) cout<<s<<'\n';
        else cout<<"---\n";
    }
}