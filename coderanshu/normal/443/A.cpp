#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    set<char> x;
    int count=0,i;
    getline(cin,s);
    for(i=1;i<s.length()-1;i+=3)
    {
        x.insert(s[i]);    
    }
    cout<<x.size();
    
    return 0; 
}