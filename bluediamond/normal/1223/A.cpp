#include <bits/stdc++.h>

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        while(q--)
        {
                int x;
                cin>>x;
                if(x==2)
                        cout<<"2\n";
                else
                        cout<<x%2<<"\n";
        }

        return 0;
}