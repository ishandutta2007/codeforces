#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<"1\n1\n";
        return 0;
    }
    if(n==2)
    {
        cout<<"1\n1\n";
        return 0;
    }
    if(n==3)
    {
        cout<<"2\n1 3\n";
        return 0;
    }
    deque<int>v={3,1,4,2};
    for(int i=5;i<=n;i++)
    {
        if(i%2==1)
        {
            v.push_back(i);
        }
        else
        {
            v.push_front(i);
        }
    }
    cout<<v.size()<<"\n";
    for(auto &it:v)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}
/**


**/