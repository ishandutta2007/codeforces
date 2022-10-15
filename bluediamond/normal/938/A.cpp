#include <bits/stdc++.h>
using namespace std;
char s[105];
int n;
bool f(char ch)
{
    if(ch=='a')return 1;
    if(ch=='e')return 1;
    if(ch=='i')return 1;
    if(ch=='o')return 1;
    if(ch=='u')return 1;
    if(ch=='y')return 1;
    return 0;
}
int main()
{
    cin>>n;
    cin.get();
    cin.getline(s,105);
    for(int i=0;i<n;i++)
    {
        if(f(s[i]) and f(s[i-1]))
            continue;
        cout<<s[i];
    }
    return 0;
}