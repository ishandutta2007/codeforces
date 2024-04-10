//  228

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a1 , a2 ,a3;

string del (string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(isupper(s[i]))
            s[i]=tolower(s[i]);
        if(s[i]=='_'   ||  s[i]==';'   ||    s[i]=='-')
            {
                s.erase(s.begin()+i,s.begin()+(i+1));
                i--;
            }
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>a1;
    cin>>a2;
    cin>>a3;
    a1=del(a1);
    a2=del(a2);
    a3=del(a3);
    int n,counter=0;;
    cin>>n;
    string s[n];
    string odd[6];
    odd[0]=a1+a2+a3;
    odd[1]=a1+a3+a2;
    odd[2]=a2+a1+a3;
    odd[3]=a2+a3+a1;
    odd[4]=a3+a1+a2;
    odd[5]=a3+a2+a1;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        s[i]=del(s[i]);
    }
    for(int i=0;i<n;i++)
    {
        counter=0;
        for(int j=0;j<6;j++)
        {
            if(s[i]==odd[j])
            {
                counter++;
                break;
            }
        }
        if(counter>0)
            cout<<"ACC"<<endl;
        else
            cout<<"WA"<<endl;
    }

    return 0;
}