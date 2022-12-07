#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, va=0, otr, otrva=-2e9;
    cin>>n;
    vector <int> bad, good;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x==0) bad.push_back(a);
        else
        {
            if(x<0)
            {
                va^=1;
                if(x>otrva) otr=a, otrva=x;
            }
            good.push_back(a);
        }
    }
    if(va)
    {
        bad.push_back(otr);
        for(int a=0; a<good.size(); a++) if(good[a]==otr) good.erase(good.begin()+a);
    }

    for(int a=1; a<bad.size(); a++) printf("1 %d %d\n", bad[a]+1, bad[0]+1);
    if(bad.size()<n and bad.size()>0) cout<<"2 "<<bad[0]+1<<"\n";

    for(int a=1; a<good.size(); a++) printf("1 %d %d\n", good[a]+1, good[0]+1);
}