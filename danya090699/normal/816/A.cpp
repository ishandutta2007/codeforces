#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, mi, q=0;
    char sy;
    cin>>h>>sy>>mi;
    while(1)
    {
        if(h/10==mi%10 and h%10==mi/10)
        {
            cout<<q;
            break;
        }
        mi++;
        if(mi==60)
        {
            h++, mi=0;
        }
        if(h==24) h=0;
        q++;
    }
}