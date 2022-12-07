#include <bits/stdc++.h>
using namespace std;
int ar[6]={4, 8, 15, 16, 23, 42};
pair <int, int> f(int x)
{
    for(int a=0; a<6; a++)
    {
        for(int b=a+1; b<6; b++)
        {
            if(x==ar[a]*ar[b])
            {
                return {ar[a], ar[b]};
            }
        }
    }
}
int main()
{
    cout<<"? 1 2\n";
    int x1;
    cin>>x1;
    pair <int, int> x12=f(x1);
    cout<<"? 2 3\n";
    int x2;
    cin>>x2;
    pair <int, int> x23=f(x2);
    cout<<"? 4 5\n";
    int x3;
    cin>>x3;
    pair <int, int> x45=f(x3);
    cout<<"? 5 6\n";
    int x4;
    cin>>x4;
    pair <int, int> x56=f(x4);

    if(x12.first==x23.first) swap(x12.first, x12.second);
    else if(x12.first==x23.second)
    {
        swap(x12.first, x12.second);
        swap(x23.first, x23.second);
    }
    else if(x12.second==x23.second) swap(x23.first, x23.second);

    if(x45.first==x56.first) swap(x45.first, x45.second);
    else if(x45.first==x56.second)
    {
        swap(x45.first, x45.second);
        swap(x56.first, x56.second);
    }
    else if(x45.second==x56.second) swap(x56.first, x56.second);

    cout<<"! "<<x12.first<<" "<<x12.second<<" "<<x23.second<<" "<<x45.first<<" "<<x45.second<<" "<<x56.second<<"\n";
}