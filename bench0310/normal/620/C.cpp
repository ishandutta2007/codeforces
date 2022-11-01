#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<array<int,2>> res;
    set<int> s;
    int l=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(s.find(a)!=s.end())
        {
            res.push_back({l,i});
            l=i+1;
            s.clear();
        }
        else s.insert(a);
    }
    if(res.empty()) printf("-1\n");
    else
    {
        res.back()[1]=n-1;
        printf("%d\n",(int)res.size());
        for(auto [a,b]:res) printf("%d %d\n",a+1,b+1);
    }
    return 0;
}