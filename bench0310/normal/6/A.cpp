#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[4];
    for(int i=0;i<4;i++) cin >> a[i];
    int best=0;
    for(int o=0;o<4;o++)
    {
        vector<int> v;
        for(int i=0;i<4;i++) if(i!=o) v.push_back(a[i]);
        sort(v.begin(),v.end());
        if(v[0]+v[1]>v[2]) best=max(best,2);
        else if(v[0]+v[1]==v[2]) best=max(best,1);
    }
    if(best==2) cout << "TRIANGLE" << endl;
    else if(best==1) cout << "SEGMENT" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}