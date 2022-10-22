#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, b[2000], c[2005], s;
vector <int> a;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        {
            cin >> b[i];
            a.push_back(b[i]);
        }
    sort(a.begin(), a.end());
    for(int i=n-k;i<n;i++)
    {
        s=s+a[i];
        c[a[i]]++;
    }
    int j=-1;
    cout << s << endl;
    for(int i=0;i<n;i++)
        if(c[b[i]]>0)
    {
        c[b[i]]--;
        k--;
        if(k>0)
        cout << i-j << ' ';
        else cout << n-j-1;
        j=i;
    }
    return 0;
}