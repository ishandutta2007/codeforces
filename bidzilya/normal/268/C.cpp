#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pii> a;
    int x = 0, y = m;
    while (x<=n && y>=0)
    {
        a.push_back(pair<int,int>(x,y));
        x++;y--;
    }
    cout << a.size() << endl;
    for (int i=0; i<a.size(); i++)cout << a[i].first << " " << a[i].second << endl;

    return 0;
}