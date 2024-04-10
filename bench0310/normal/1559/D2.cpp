#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m1,m2;
    cin >> m1 >> m2;
    vector<array<int,2>> edges1(m1),edges2(m2);
    for(auto &[a,b]:edges1) cin >> a >> b;
    for(auto &[a,b]:edges2) cin >> a >> b;
    if(m1<m2)
    {
        swap(m1,m2);
        swap(edges1,edges2);
    }
    vector<int> p1(n+1,0);
    set<array<int,2>> s1[n+1]; //col,a
    for(int i=1;i<=n;i++)
    {
        p1[i]=i;
        s1[i].insert({i,i});
    }
    vector<int> p2(n+1,0);
    vector<int> v2[n+1];
    for(int i=1;i<=n;i++)
    {
        p2[i]=i;
        v2[i].push_back(i);
    } 
    set<array<int,2>> singles; //col,a
    set<int> doubles;
    function<int(int)> find_set1=[&](int a)->int
    {
        if(a==p1[a]) return a;
        else return p1[a]=find_set1(p1[a]);
    };
    function<int(int)> find_set2=[&](int a)->int
    {
        if(a==p2[a]) return a;
        else return p2[a]=find_set2(p2[a]);
    };
    auto is_single=[&](int a)->int
    {
        if((*s1[a].begin())[0]!=(*s1[a].rbegin())[0]) return 0;
        else return (*s1[a].begin())[0];
    };
    auto change=[&](int a,int t) //fix singles/doubles of a, 0-add 1-rm
    {
        int c=is_single(a);
        if(c!=0)
        {
            if(t==0) singles.insert({c,a});
            else singles.erase({c,a});
        }
        else
        {
            if(t==0) doubles.insert(a);
            else doubles.erase(a);
        }
    };
    for(int i=1;i<=n;i++) change(i,0);
    auto merge_sets1=[&](int a,int b)
    {
        a=find_set1(a);
        b=find_set1(b);
        assert(a!=b);
        change(a,1);
        change(b,1);
        if(s1[a].size()<s1[b].size()) swap(a,b);
        for(auto [c,x]:s1[b]) s1[a].insert({c,x});
        s1[b].clear();
        p1[b]=a;
        change(a,0);
    };
    auto merge_sets2=[&](int a,int b)
    {
        a=find_set2(a);
        b=find_set2(b);
        assert(a!=b);
        if(v2[a].size()<v2[b].size()) swap(a,b);
        for(int x:v2[b])
        {
            int p=find_set1(x);
            change(p,1);
            s1[p].erase({b,x});
            s1[p].insert({a,x});
            change(p,0);
            v2[a].push_back(x);
        }
        v2[b].clear();
        p2[b]=a;
    };
    for(auto [a,b]:edges1) merge_sets1(a,b);
    for(auto [a,b]:edges2) merge_sets2(a,b);
    cout << n-1-m1 << "\n";
    auto add_edge=[&](int a,int b)
    {
        cout << a << " " << b << "\n";
        merge_sets1(a,b);
        merge_sets2(a,b);
    };
    while(int(singles.size()+doubles.size())>1)
    {
        if(!doubles.empty())
        {
            int one=*doubles.begin();
            int two=0;
            if(!singles.empty()) two=(*singles.begin())[1];
            else two=*(next(doubles.begin()));
            auto [col1,a1]=(*s1[one].begin());
            auto [col2,a2]=(*s1[one].rbegin());
            assert(col1!=col2);
            auto [col,b]=(*s1[two].begin());
            if(col!=col1) add_edge(a1,b);
            else if(col!=col2) add_edge(a2,b);
        }
        else
        {
            auto [col1,a1]=(*singles.begin());
            auto [col2,a2]=(*singles.rbegin());
            assert(col1!=col2);
            add_edge(a1,a2);
        }
    }
    return 0;
}