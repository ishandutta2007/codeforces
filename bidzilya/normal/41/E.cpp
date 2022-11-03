#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<pair<int,int> > g;
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j+=2)
            g.push_back(pair<int,int>(i,j));
    cout << g.size() << endl;
    for (int i=0; i<g.size(); i++) cout << g[i].first << " " << g[i].second << endl;
    return 0;
}