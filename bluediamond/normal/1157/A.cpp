#include <bits/stdc++.h>

using namespace std;

int urm(int x)
{
        x++;
        while(x%10==0)
        {
                x/=10;
        }
        return x;
}

int main()
{
        int x;
        cin>>x;
        set <int> s;
        s.insert(x);
        while(1)
        {
                x=urm(x);
                if(s.find(x)!=s.end())
                {
                        break;
                }
                s.insert(x);
        }
        cout<<(int)s.size()<<"\n";
        return 0;
}