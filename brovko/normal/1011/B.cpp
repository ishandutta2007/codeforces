#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, a, c[101], ans, k;
vector <int> b;
bool sort_function(int i, int j)
{
    if(i>j)
        return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    if(n>m)
    {
        for(int i=0;i<m;i++)
            cin >> a;
        cout << 0;
    }
    else
    {
    for(int i=0;i<m;i++)
    {
        cin >> a;
        c[a]++;
    }
    for(int i=0;i<101;i++)
        b.push_back(c[i]);
    sort(b.begin(), b.end(), sort_function);
    ans=1;
    bool f=true;
    while(f)
    {
        k=0;
        for(int i=0;i<101;i++)
            k+=b[i]/ans;
        if(k>=n)
            ans++;
        else f=false;
    }
    cout << ans-1;
    }
    return 0;
}