#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x=0;
    int y=1023;
    while(n--)
    {
        char t;
        int a;
        cin >> t >> a;
        if(t=='&')
        {
            x&=a;
            y&=a;
        }
        if(t=='|')
        {
            x|=a;
            y|=a;
        }
        if(t=='^')
        {
            x^=a;
            y^=a;
        }
    }
    int a=1023;
    int b=0;
    int c=0;
    for(int i=0;i<10;i++)
    {
        if(((x>>i)&1)==0&&((y>>i)&1)==0) a^=(1<<i);
        else if(((x>>i)&1)==1&&((y>>i)&1)==1) b^=(1<<i);
        else if(((x>>i)&1)==1&&((y>>i)&1)==0) c^=(1<<i);
    }
    cout << "3\n";
    cout << "& " << a << "\n";
    cout << "| " << b << "\n";
    cout << "^ " << c << "\n";
    return 0;
}