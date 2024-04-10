#include <bits/stdc++.h>

using namespace std;

int n, a[20];
vector<pair<int, int>> sol;

void Move(int first, int from, int to, bool rev)
{
        if (first>=n)
                return;

        int last=first;
        while (last+1<n && a[last+1]==a[last])
                last++;

        int other=6-from-to;

        if (first==last)
                rev=1;

        if (rev)
        {
                Move(last+1, from, other, 1);
                for (int j=first; j<=last; j++)
                        sol.push_back({from, to});
                Move(last+1, other, to, 1);
        }
        else
        {
                if (last==n-1)
                {
                        for (int j=first; j<last; j++)
                                sol.push_back({from, other});
                        sol.push_back({from, to});
                        for (int j=first; j<last; j++)
                                sol.push_back({other, to});
                        return;
                }

                Move(last+1, from, to, 1);
                for (int j=first; j<=last; j++)
                        sol.push_back({from, other});
                Move(last+1, to, from, 1);
                for (int j=first; j<=last; j++)
                        sol.push_back({other, to});
                Move(last+1, from, to, 0);
        }
}

int main()
{
        cin>>n;
        for (int i=0; i<n; i++)
        {
                cin>>a[i];
        }



        Move(0, 1, 3, 0);


        cout<<(int) sol.size()<<"\n";
        for (auto &it : sol)
        {
                cout<<it.first<<" "<<it.second<<"\n";
        }





        return 0;
}