#include <bits/stdc++.h>

using namespace std;

int p1,p2;

int cnt=0;

int nr=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>p1>>p2;
    while(p1>0 && p2>0)
    {
        if(p1>p2)
            swap(p1,p2);
        p1++;
        p2-=2;
        if(p1>=0 && p2>=0)
            cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
/**

**/